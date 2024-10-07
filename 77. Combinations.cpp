// ---------------------- Approach - 1 ------------------------
// Using Backtracking

class Solution {
public:
    void combinations(int start, int n, int k, vector<int>& temp, vector<vector<int>>& result){
        if(k == 0){
            result.push_back(temp);
            return;
        }

        if(start > n){
            return;
        }

        temp.push_back(start);
        combinations(start+1, n, k - 1, temp, result);
        temp.pop_back();
        combinations(start+1, n, k, temp, result);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;

        combinations(1, n, k, temp, result);

        return result;
    }
};

// ---------------------- Approach - 2 ------------------------

class Solution {
public:
    vector<vector<int>> result;

    void combinations(int start, int& n, int k, vector<int>& temp){
        if(k == 0){
            result.push_back(temp);
            return;
        }

        for(int i = start; i <= n; i++){
            temp.push_back(i);
            combinations(i + 1, n, k - 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;

        combinations(1, n, k, temp);

        return result;
    }
};