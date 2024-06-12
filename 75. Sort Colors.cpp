// --------------------------- Approach - 1 (Brute Force) -----------------------------------------

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 1;

        while(i < n){
            if(j == n){
                i++;
                j = i;
                continue;
            }
            if(nums[i] <= nums[j]){
                // j++;
            }
            else{
                swap(nums[i], nums[j]);
            }
            j++;
        }
    }
};

// --------------------------- Approach - 1 (Optimal) -----------------------------------------

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int i = 0; // deno
        int j = 0;
        int k = n-1;

        while(j <= k){
            if(nums[j] == 1){
                j++;
            }
            else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k--;
            }
            else{ // nums[j] == 0
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};