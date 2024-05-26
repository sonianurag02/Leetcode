class Solution {
public:
    int t[101][101];
    int m, n;

    int solve(int i, int j, vector<vector<int>>& obstacleGrid){
        if(i == m-1 && j == n-1 && obstacleGrid[m-1][n-1] == 0) return 1;

        if(i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] == 1) return 0;

        if(t[i][j] != -1){
            return t[i][j];
        }

        int right = solve(i, j+1, obstacleGrid);
        int down = solve(i+1, j, obstacleGrid);

        return t[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        memset(t, -1, sizeof(t));

        return solve(0, 0, obstacleGrid);
    }
};
