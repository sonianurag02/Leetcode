// ------------------ Solution - Bit Manipulation -----------------

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            ans = ans ^ nums[i];
        }

        return ans;
    }
};