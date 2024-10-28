// ----------------------------------- Approach - 1 ------------------------------------
// Recusrion + Memoization

class Solution {
public:
    int m, n;

    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& t){
        if(i >= m || j >= n){
            return 0;
        }

        if(matrix[i][j] == 0){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int right = solve(i, j+1, matrix, t);
        int diag = solve(i+1, j+1, matrix, t);
        int below = solve(i+1, j, matrix, t);

        return t[i][j] = 1 + min({right, diag, below});
    }

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        int result = 0;

        vector<vector<int>> t(m+1, vector<int>(n+1, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    result += solve(i, j, matrix, t);
                }
            }
        }

        return result;
    }
};

// ----------------------------------- Approach - 2 ------------------------------------
// Bottom-up

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int result = 0; // Total number of square submatrices having only 1s

        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        // t[i][j] = Total square submatrices (having 1s) ending at [i][j]

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){ // 0th row or 0th column
                    t[i][j] = matrix[i][j];
                } else if(matrix[i][j] == 1){
                    t[i][j] = 1 + min({t[i][j-1], t[i-1][j-1], t[i-1][j]});
                }

                result += t[i][j];
            }
        }

        return result;
    }
};