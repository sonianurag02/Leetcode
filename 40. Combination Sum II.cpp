// ----------------------------- Approach - 1 -----------------------------
// Backtracking

class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& curr, int idx, vector<vector<int>>& result){
        if(target < 0){
            return;
        }

        if(target == 0){
            result.push_back(curr);
        }

        for(int i = idx; i < candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }

            curr.push_back(candidates[i]); // Do
            solve(candidates, target - candidates[i], curr, i+1, result); // Explore
            curr.pop_back(); // Undo
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        sort(begin(candidates), end(candidates));
        solve(candidates, target, curr, 0, result);

        return result;
    }
};