// --------------- Approach - 1 (Brute Force) --------------------

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), 0));

        int k = 0;
        for(int i = matrix.size() - 1; i >= 0; i--){
            for(int j = 0; j < matrix[0].size(); j++){
                res[j][k] = matrix[i][j];
            }
            k++;
        }

        matrix = res;
    }
};

// --------------- Approach - 2 (Optimal) --------------------

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m;

        // Transpose matrix
        for(int i = 0; i < m; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse Matrix
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};