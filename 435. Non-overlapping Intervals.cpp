// --------- Approach - 1 (Sorting Based on first index) --------------------------

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int m = intervals.size();
        sort(begin(intervals), end(intervals));

        int count = 0;
        int curr_end = intervals[0][1];
        for(int i = 1; i < m; i++){
            if(intervals[i][0] < curr_end){
                count++;
                curr_end = min(curr_end, intervals[i][1]);
            }
            else{
                curr_end = intervals[i][1];
            }
        }

        return count;
    }
};

// --------- Approach - 2 (Sorting Based on last index) --------------------------

class Solution {
public:
    // For code fastening
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));

        int n = intervals.size();
        int count = 0;
        int i = 1;
        vector<int> L = intervals[0];

        while(i < n){
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            int last_end = L[1];

            if(curr_start >= last_end){
                L = intervals[i];
            }
            else if(curr_end >= last_end){
                count++;
            }
            else if(curr_end < last_end){
                L = intervals[i];
                count++;
            }
            i++;
        }
        return count;
    }
};