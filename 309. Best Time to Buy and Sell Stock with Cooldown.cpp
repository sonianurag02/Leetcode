// ------------------- Recursion + Memoization ----------------------------------

class Solution {
public:
    int t[5001][2];

    int solve(vector<int>& prices, int day, int n, bool buy){
        if(day >= n) return 0;

        if(t[day][buy] != -1) return t[day][buy];

        int profit = 0;

        // buy
        if(buy){
            int take = solve(prices, day+1, n, false) - prices[day];

            int not_take = solve(prices, day+1, n, true);

            profit = max({profit, take, not_take});
        }
        // sell
        else{
            int sell = prices[day] + solve(prices, day+2, n, true);

            int not_sell = solve(prices, day+1, n, false);

            profit = max({profit, sell, not_sell});
        }

        return t[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        memset(t, -1, sizeof(t));

        bool buy = true;

        return solve(prices, 0, n, buy);
    }
};

// ----------------------- Bottom-up Approach ------------------------------------

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if(n == 0 || n == 1) return 0;

        vector<int> t(n, 0);

        // t[i] = max total profit until day i

        t[0] = 0;
        t[1] = max(prices[1] - prices[0], 0);

        for(int  i = 2; i < n; i++){
            t[i] = t[i-1];

            for(int j = 0; j <= i-1; j++){
                int today_profit = prices[i] - prices[j];

                int prev_profit = j >= 2 ? t[j-2] : 0; // Why ?
                /*
                kyuki jth day me buy kar rahe hai, so,
                j-1 me sell nahi kar sakte (cool down period)
                j-1 ko buy bhi nahi kar sakte pakka cool down
                */
                t[i] = max(t[i], today_profit+prev_profit);
            }
        }

        return t[n-1];
    }
};