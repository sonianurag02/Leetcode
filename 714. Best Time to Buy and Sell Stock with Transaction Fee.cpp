// -------------------------- Recursion + Memoization --------------------------------

class Solution {
public:
    int t[50001][2];
    int FEE; 

    int solve(vector<int>& prices, int day, int n, int buy){
        if(day >= n) return 0;

        int profit = 0;

        if(t[day][buy] != -1) return t[day][buy];

        // buy
        if(buy){
            int take = solve(prices, day+1, n, false) - prices[day];

            int not_take = solve(prices, day+1, n, true);

            profit = max({profit, take, not_take});
        }
        // sell
        else{
            int sell = prices[day] + solve(prices, day+1, n, true) - FEE;

            int not_sell = solve(prices, day+1, n, false);

            profit = max({profit, sell, not_sell});
        }

        return t[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        FEE = fee;

        memset(t, -1, sizeof(t));

        return solve(prices, 0, n, true);
    }
};