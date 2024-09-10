// -------------------------------- Approach - 1 -----------------------------------

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < buy){
                buy = prices[i];
            }
            else{
                ans = max(ans , prices[i] - buy);
            } 
        }
        return ans;
    }
};