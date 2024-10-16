// ---------------------- Approach - 1 ----------------------
// Using Recursion & backtracking

// T.C. ~ O(N!)

class Solution {
public:
    vector<vector<string>> result;
    int N;

    bool isValid(vector<string>& board, int row, int col){
        // Look upward
        for(int i = row - 1; i >= 0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // Check left diagonal upwards
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // Check right diagonal upwards
        for(int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }

    void solve(vector<string>& board, int row){
        if(row >= N){
            result.push_back(board);
            return;
        }

        for(int col = 0; col < N; col++){
            if(isValid(board, row, col)){
                board[row][col] = 'Q';

                solve(board, row + 1);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;

        vector<string> board(n, string(n, '.'));

        solve(board, 0);

        return result;
    }
};

// ---------------------- Approach - 2 ----------------------
// Better Approach

// T.C. ~ O(N!)

class Solution {
public:
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;
    int N;

    void solve(vector<string>& board, int row){
        if(row >= N){
            result.push_back(board);
            return;
        }

        for(int col = 0; col < N; col++){
            int diagConst = row + col;
            int antiDiagConst = row - col;

            if(cols.find(col) != cols.end() || diag.find(diagConst) != diag.end() || antiDiag.find(antiDiagConst) != antiDiag.end()){
                continue;
            }
            
            // For a given [row][col] = 'Q'
            cols.insert(col);
            diag.insert(diagConst);
            antiDiag.insert(antiDiagConst);
            board[row][col] = 'Q';

            solve(board, row + 1);
            
            cols.erase(col);
            diag.erase(diagConst);
            antiDiag.erase(antiDiagConst);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;

        vector<string> board(n, string(n, '.'));

        solve(board, 0);

        return result;
    }
};