// ------------------------- Code ---------------------------------

class Solution {
public:
    vector<vector<int>> result;

    void twoSum(vector<int>& nums, int target, int start, int end){
        while(start < end){
            if(nums[start] + nums[end] > target){
                end--;
            }
            else if(nums[start] + nums[end] < target){
                start++;
            }
            else{
                while(start < end && nums[start] == nums[start + 1]) start++;

                while(start < end && nums[end] == nums[end - 1]) end--;

                result.push_back({-target, nums[start], nums[end]});

                start++;
                end--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        if(n < 3){
            return {};
        }

        result.clear();

        sort(nums.begin(), nums.end());

        for(int i = 0; i <= n - 3; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int n1 = nums[i];
            int target = -n1;

            twoSum(nums, target, i+1, n-1);
        }

        return result;
    }
};