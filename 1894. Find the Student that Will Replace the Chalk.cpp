// ------------------------------- Approach - 1 --------------------------------------
// Brute Force
// Time Limit Exceed

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        while(true){
            for(int i = 0; i < chalk.size(); i++){
                if(k < chalk[i]){
                    return i;
                }
                k -= chalk[i];
            }
        }
        return -1;
    }
};

// ------------------------------- Approach - 2 --------------------------------------
// Linear Search

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long totalChalkSum = 0;
        for(int& chalkReq: chalk){
            totalChalkSum += chalkReq;
            if(totalChalkSum > k){
                break;
            }
        }

        int remainingChalk = k % totalChalkSum;

        for(int i = 0; i < n; i++){
            if(remainingChalk < chalk[i]){
                return i;
            }
            remainingChalk -= chalk[i];
        }

        return -1;
    }
};