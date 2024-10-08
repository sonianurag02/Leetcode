// ------------------------- Approach - 1 -----------------------
// Using Backtracking

class Solution {
public:
    vector<vector<int>> result;

    void combinations(int idx, int target, vector<int>& arr, vector<int>& temp){
        if(idx == arr.size()){
            if(target == 0){
                result.push_back(temp);
            }
            return;
        }

        // Pickup the element
        if(arr[idx] <= target){
            temp.push_back(arr[idx]);
            combinations(idx, target - arr[idx], arr, temp);
            temp.pop_back();
        }
        combinations(idx + 1, target, arr, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;

        combinations(0, target, candidates, temp);

        return result;
    }
};