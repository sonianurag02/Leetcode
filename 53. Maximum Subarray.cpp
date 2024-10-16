// -------------------- Approach - 1 ------------------------------
// Brute Force
// TLE

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int result = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = i, currSum = 0; j < n; j++){
                currSum += nums[j];
                result = max(result, currSum);
            }
        }

        return result;
    }
};

// -------------------- Approach - 2 ------------------------------
// Kadane's Algo

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int result = INT_MIN;

        for(int& num: nums){
            sum += num;

            if(sum > result){
                result = sum;
            }

            if(sum < 0){
                sum = 0;
            }
        }

        return result;
    }
};

// -------------------- Approach - 3 ------------------------------
// Kadane's Algo

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currMax = 0;
        int maxTillNow = INT_MIN;

        for(auto& num: nums){
            currMax = max(num, currMax + num);
            maxTillNow = max(maxTillNow, currMax);
        }

        return maxTillNow;
    }
};