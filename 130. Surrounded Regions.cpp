// -------------------------- Approach - 1 --------------------------
// DFS

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int delRow[], int delCol[]){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, vis, board, delRow, delCol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1}; 

        vector<vector<int>> vis(n, vector<int>(m,0)); 

        // traverse first row and last row 
        for(int j = 0; j < m; j++) {
            // check for unvisited Os in the boundary rows
            // first row 
            if(!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, delrow, delcol); 
            }
            
            // last row 
            if(!vis[n-1][j] && board[n-1][j] == 'O') {
                dfs(n-1, j, vis, board, delrow, delcol); 
            }
        }
        
        for(int i = 0; i < n; i++) {
            // check for unvisited Os in the boundary columns
            // first column 
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, delrow, delcol); 
            }
            
            // last column
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, vis, board, delrow, delcol); 
            }
        }
        
        // if unvisited O then convert to X
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && board[i][j] == 'O') 
                    board[i][j] = 'X'; 
            }
        }
    }
};