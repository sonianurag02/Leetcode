// ------------------------------- Approach - 1 ---------------------------------------
// Sliding Window

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp(n*2);
        for(int i = 0; i < 2*n; i++){
            temp[i] = nums[i%n];
        }

        int totalOnes = accumulate(begin(nums), end(nums), 0); // Total number of ones

        int currOnes = 0;
        int maxCount = 0;

        int i = 0;
        int j = 0;

        while(j < 2*n){
            if(temp[j] == 1){
                currOnes++;
            }

            if(j-i+1 > totalOnes){
                currOnes -= temp[i];
                i++;
            }

            maxCount = max(maxCount, currOnes);
            j++;
        }

        return totalOnes - maxCount;
    }
};

// ------------------------------- Approach - 2 ---------------------------------------

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int totalOnes = accumulate(begin(nums), end(nums), 0); // Total number of ones

        int currOnes = 0;
        int maxCount = 0;

        int i = 0;
        int j = 0;

        while(j < 2*n){
            if(nums[j%n] == 1){
                currOnes++;
            }

            if(j-i+1 > totalOnes){
                currOnes -= nums[i%n];
                i++;
            }

            maxCount = max(maxCount, currOnes);
            j++;
        }

        return totalOnes - maxCount;
    }
};