// ----------------------- Approach - 1 (Brute Force) ----------------------------------

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] < nums[i+1]){
                continue;
            }
            else{
                while(nums[i] >= nums[i+1]){
                    nums[i+1]++;
                    ans++;
                }
            }
        }
        return ans;
    }
};

// ----------------------- Approach - 2 (A little bit better) ----------------------------------

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int minIncrements = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                int increments = nums[i-1] + 1 - nums[i];
                minIncrements += increments;

                nums[i] = nums[i-1] + 1;
            }
        }
        return minIncrements;
    }
};

// ----------------------- Approach - 3 (Counting) ----------------------------------

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int max_val = 0;
        int minIncrements = 0;

        for(int val: nums){
            max_val = max(max_val, val);
        }

        vector<int> freqCount(n + max_val+1, 0);

        for(int val: nums){
            freqCount[val]++;
        }

        for(int i = 0; i < freqCount.size(); i++){
            if(freqCount[i] <= 1){
                continue;
            }
            int duplicates = freqCount[i] - 1;
            freqCount[i + 1] += duplicates;
            freqCount[i] = 1;
            minIncrements += duplicates;
        }

        return minIncrements;
    }
};