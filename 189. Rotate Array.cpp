// ---------------------- Approach - 1 --------------------------

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        
        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};

// ---------------------- Approach - 2 --------------------------

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int rotations = k % n, regular = 0;

        if(rotations == 0) return;

        vector<int> temp(n);

        for(int i = 0; i < n; i++){
            if(rotations > 0){
                temp[i] = nums[n - rotations];
                rotations--;
            }
            else{
                temp[i] = nums[regular];
                regular++;
            }
        }
        nums = temp;
    }
};