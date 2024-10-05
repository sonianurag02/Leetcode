// ----------------------- Approach - 1 -----------------------
// Backtracking

class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void backtrack(int idx, vector<int>& nums, vector<vector<int>>& result){
        if(idx == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);

            backtrack(idx+1, nums, result);

            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        backtrack(0, nums, result);

        return result;
    }
};