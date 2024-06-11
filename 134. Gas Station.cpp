// -------------------------- Approach - 1 (Brute Force) TLE ----------------------------------

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for(int i = 0; i < n; i++){
            if(gas[i] < cost[i]){
                continue;
            }
            int j = (i+1) % n;

            int costForMovingFromThisStation = cost[i];
            int gasEarnInNextStation = gas[j];

            int currGas = gas[i] - costForMovingFromThisStation + gasEarnInNextStation;

            while(j != i){
                if(currGas < cost[j]){
                    break;
                }

                int costForMovingFromThisj = cost[j];
                j = (j+1) % n;
                int gasEarnInNextStationj = gas[j];

                currGas = currGas - costForMovingFromThisj + gasEarnInNextStationj;
            }
            if(j == i){
                return i;
            }
        }
        return -1;
    }
};

// -------------------------- Approach - 2 (Optimal) ----------------------------------

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        // To find total sum
        int totalKamai = accumulate(gas.begin(), gas.end(), 0);
        int totalKharch = accumulate(cost.begin(), cost.end(), 0);

        if(totalKamai < totalKharch){
            return -1;
        }

        int total = 0;
        int resultIdx = 0;

        for(int i = 0; i < n; i++){
            total += gas[i] - cost[i];

            if(total < 0){
                resultIdx = i+1;
                total = 0;
            }
        }
        return resultIdx;
    }
};