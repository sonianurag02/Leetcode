// ----------------------------- Approach - 1 -----------------------------

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(false);
        
        int n = customers.size();
        long long waitTime = 0;
        int idleTime = 0;

        for(int i = 0; i < n; i++){
            idleTime = max(customers[i][0], idleTime) + customers[i][1];

            waitTime += idleTime - customers[i][0];
        }

        return (double)waitTime / n;
    }
};

// ---------------------------------- Approach - 2 -------------------------

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        int n = customers.size();

        double totalWaitTime = 0;
        int currTime = 0;

        for(auto& vec: customers){
            int arrivalTime = vec[0];
            int cookTime = vec[1];

            if(currTime < arrivalTime){
                currTime = arrivalTime;
            }

            int waitTime = currTime + cookTime - arrivalTime;

            totalWaitTime += waitTime;

            currTime += cookTime;
        }

        return totalWaitTime / n;
    }
};