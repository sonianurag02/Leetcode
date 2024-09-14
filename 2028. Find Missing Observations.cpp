// --------------------------- Approach - 1 ------------------------------

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;

        for(int num: rolls){
            sum += num;
        }

        int remainingSum = mean * (n + rolls.size()) - sum;

        if(remainingSum > 6 * n || remainingSum < n){
            return {};
        }

        int distributedMean = remainingSum / n;
        int mod = remainingSum % n;

        vector<int> nElement(n, distributedMean);
        for(int i = 0; i < mod; i++){
            nElement[i]++;
        }

        return nElement;
    }
};