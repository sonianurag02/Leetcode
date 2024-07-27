// --------------------------------- Approach - 1 ---------------------------------

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }

        sort(nums.begin(), nums.end());

        int result = 0;
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                if(nums[i] == nums[i-1] + 1){
                    count++;
                } else{
                    result = max(result, count);
                    count = 1;
                }
            }
        }

        return max(result, count);
    }
};