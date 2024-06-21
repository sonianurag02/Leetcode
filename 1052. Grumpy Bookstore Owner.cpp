// ----------------------------------- Code --------------------------------------------

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int maxSat = 0;
        int currSat = 0;

        for(int i = 0; i < minutes; i++){
            currSat += customers[i] * grumpy[i];
        }

        maxSat = currSat;

        int i = 0; 
        int j = minutes;

        while(j < n){
            currSat += customers[j] * grumpy[j];
            currSat -= customers[i] * grumpy[i];

            maxSat = max(maxSat, currSat);

            i++;
            j++;
        }

        int totalSat = maxSat;
        for(int i = 0; i < n; i++){
            totalSat += customers[i] * (1 - grumpy[i]);
        }

        return totalSat;
    }
};