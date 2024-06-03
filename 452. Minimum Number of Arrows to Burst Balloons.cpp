// --------------------------- Approach - 1 -----------------------------------

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points));

        int n = points.size();
        int burst = 1;
        vector<int> prev = points[0];

        for(int i = 1; i < n; i++){
            int cs = points[i][0];
            int ce = points[i][1];

            int ps = prev[0];
            int pe = prev[1];

            if(cs > pe){
                burst++;
                prev = points[i];
            }
            else{
                prev[0] = max(ps, cs);
                prev[1] = min(pe, ce);
            }
        }
        
        return burst;
    }
};