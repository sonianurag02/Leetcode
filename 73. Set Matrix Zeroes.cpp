// ---------------------------- Approach - 1 (Brute force) ----------------------------

class Solution {
public:
    void fillZeroes(vector<vector<int>>& matrix, int i, int j){
        for(int l = 0; l < matrix[0].size(); l++){
            if (matrix[i][l] != 0) {
                matrix[i][l] = '~';
            }
        }
        for(int l = 0; l < matrix.size(); l++){
            if (matrix[l][j] != 0) {
                matrix[l][j] = '~';
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(m == 0 || n == 0){
            return;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    fillZeroes(matrix, i, j);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '~'){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// ------------------------------- Approach - 2 -------------------------------

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();     
        int n = matrix[0].size();   
        int col[n],row[m];
        
        for(int i=0;i<n;i++) col[i] = 1;    
        for(int i=0;i<m;i++) row[i] = 1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==0 || col[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};