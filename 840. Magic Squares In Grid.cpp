// ------------------------------ Approach - 1 ------------------------------------
// Brute Force

class Solution {
public:
    bool helper(vector<vector<int>>& grid, int row, int col){
        // Check if all numbers are distinct and between 1 and 9
        vector<int> freq(10, 0);
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9 || freq[grid[i][j]] > 0) {
                    return false;
                }
                freq[grid[i][j]]++;
            }
        }

        // Calculate the sum of the first row
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];

        // Check rows
        for (int i = row; i < row + 3; i++) {
            int tempSum = 0;
            for (int j = col; j < col + 3; j++) {
                tempSum += grid[i][j];
            }
            if (tempSum != sum) {
                return false;
            }
        }

        // Check columns
        for (int j = col; j < col + 3; j++) {
            int tempSum = 0;
            for (int i = row; i < row + 3; i++) {
                tempSum += grid[i][j];
            }
            if (tempSum != sum) {
                return false;
            }
        }

        // Check diagonals
        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != sum) {
            return false;
        }
        if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] != sum) {
            return false;
        }

        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m < 3 || n < 3){
            return 0;
        }

        int count = 0;

        for(int i = 0; i < m-2; i++){
            for (int j = 0; j <= n - 3; j++) {
                if (helper(grid, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};