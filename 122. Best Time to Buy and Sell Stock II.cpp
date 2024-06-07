// ------------------------ Approach - 1 (Using DP) ---------------------

class Solution {
public:
    int t[100005][2];

    int maxProfit(int i, int canBuy, vector<int>& prices){
        int n = prices.size();

        if(i == n) return 0;

        if(t[i][canBuy] != -1) return t[i][canBuy];

        if(canBuy){
            t[i][canBuy] = max(-prices[i] + maxProfit(i+1, 0, prices), maxProfit(i+1, 1, prices));
        }
        else{
            t[i][canBuy] = max(prices[i] + maxProfit(i+1, 1, prices), maxProfit(i+1, 0, prices));
        }
        return t[i][canBuy];
    }

    int maxProfit(vector<int>& prices) {
        memset(t, -1, sizeof(t));

        return maxProfit(0, 1, prices);
    }
};

// ------------------- Approach - 2 --------------------------------

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int start = prices[0];
        int len = prices.size();

        for(int i = 1; i < len; i++){
            if(start < prices[i]){
                max += prices[i] - start;
            }
            start = prices[i];
        }
        return max;
    }
};

