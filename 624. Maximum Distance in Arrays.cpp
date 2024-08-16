// ------------------------------- Approach - 1 ------------------------------------

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int smallest = arrays[0][0];
        int largest = arrays[0].back();

        int result = 0;

        for(int i = 1; i < n; i++){
            result = max(result, abs(arrays[i].back() - smallest));
            result = max(result, abs(largest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            largest = max(largest, arrays[i].back());
        }

        return result;
    }
};