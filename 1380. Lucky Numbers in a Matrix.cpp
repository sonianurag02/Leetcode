// ---------------------------------- Approach - 1 -----------------------------------

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        vector<int> minRow;
        vector<int> maxCol;

        for(int i = 0; i < matrix.size(); i++){
            int mini = INT_MAX;
            for(int j = 0; j < matrix[i].size(); j++){
                mini = min(mini, matrix[i][j]);
            }
            minRow.push_back(mini);
        }

        for(int i = 0; i < matrix[0].size(); i++){
            int maxi = INT_MIN;
            for(int j = 0; j < matrix.size(); j++){
                maxi = max(maxi, matrix[j][i]);
            }
            maxCol.push_back(maxi);
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]){
                    res.push_back(matrix[i][j]);
                }
            }
        }

        return res;
    }
};

// ---------------------------------- Approach - 2 -----------------------------------

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rMinMax = INT_MIN;
        int cMaxMin = INT_MAX;

        for(int i = 0; i < matrix.size(); i++){
            int mini = INT_MAX;
            for(int j = 0; j < matrix[i].size(); j++){
                mini = min(mini, matrix[i][j]);
            }
            rMinMax = max(rMinMax, mini);
        }

        for(int i = 0; i < matrix[0].size(); i++){
            int maxi = INT_MIN;
            for(int j = 0; j < matrix.size(); j++){
                maxi = max(maxi, matrix[j][i]);
            }
            cMaxMin = min(cMaxMin, maxi);
        }

        if(rMinMax == cMaxMin){
            return {rMinMax};
        }

        return {};
    }
};