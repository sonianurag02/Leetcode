// ---------------------- Approach - 1 --------------------------------------

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int size = nums.size();

        if(size <= 4) return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        for(int left = 0, right = size - 4; left < 4; left++, right++){
            minDiff = min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
};