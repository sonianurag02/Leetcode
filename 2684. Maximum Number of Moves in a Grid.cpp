// -------------------------------- Approach - 1 --------------------------------
// using recursion

class Solution {
public:
    const int dx[3] = {-1, 1, 0};
    const int dy[3] = {1, 1, 1};

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c){
        if(vis[i][j] || i < 0 || i >= r || j < 0 || j >= c) return 0;

        vis[i][j] = 1;
        int score = 0, maxi = 0;
        for(int x = 0; x < 3; x++){
            int newi = i + dx[x];
            int newj = j + dy[x];

            if(newi >= 0 && newi < r && newj >= 0 && newj < c && grid[newi][newj] > grid[i][j]){
                score = 1 + dfs(newi, newj, grid, vis, r, c);
                maxi = max(maxi, score);
            }
        }

        return maxi;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int maxi = 0;
        vector<vector<int>> vis(r, vector<int>(c, 0));

        for(int i = 0; i < r; i++){
            maxi = max(dfs(i, 0, grid, vis, r, c), maxi);
        }

        return maxi;
    }
};