// ---------------------------- Approach - 1 -----------------------------
// Using Kadane's Algorithm

class Solution {
public:
    int kadanesMax(vector<int>& nums, int n){
        int sum = nums[0];
        int maxSum = nums[0];
        
        for(int i = 1; i < n; i++){
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    int kadanesMin(vector<int>& nums, int n){
        int sum = nums[0];
        int minSum = nums[0];
        
        for(int i = 1; i < n; i++){
            sum = min(sum + nums[i], nums[i]);
            minSum = min(minSum, sum);
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        int minSum = kadanesMin(nums, n);

        int maxSum = kadanesMax(nums, n);

        int circularSum = sum - minSum;

        if(maxSum > 0){
            return max(maxSum, circularSum);
        }

        return maxSum;
    }
};