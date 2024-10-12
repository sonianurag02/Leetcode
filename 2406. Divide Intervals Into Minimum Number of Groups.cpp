// --------------------------- Approach - 1 ----------------------------------
// Using min-heap

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Step - 1: Sort based on starting point
        sort(begin(intervals), end(intervals)); // O(nlog(n))

        // Step - 2: Define min-heap to store ending points of each group
        priority_queue<int, vector<int>, greater<int>> pq; // S.C.: O(n)

        // Step - 3: Process each interval one by one
        for(vector<int>& interval: intervals){ // O(n)
            int start = interval[0];
            int end = interval[1];

            if(!pq.empty() && start > pq.top()){
                pq.pop(); // O(log(n))
            }

            pq.push(end); // O(log(n))
        }

        // Step - 4: size of heap (which is nothing but number of groups)
        return pq.size();
    }
};