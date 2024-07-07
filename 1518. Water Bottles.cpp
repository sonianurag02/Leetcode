// -------------------------- Approach - 1 (Brute Force Approach) -------------------------------

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int res = 0;
        int leftEmptyBottles = 0;
        int toBeFull = 0;

        while(numBottles > 0){
            res += numBottles;
            emptyBottles = numBottles;
            toBeFull = (emptyBottles + leftEmptyBottles) / numExchange;
            // cout<<emptyBottles + leftEmptyBottles<<" ";
            numBottles = toBeFull;
            leftEmptyBottles = (emptyBottles  + leftEmptyBottles) % numExchange;
            cout<<leftEmptyBottles<<" ";
        }

        return res;
    }
};

// ------------------------------------- Approach - 2 -------------------------------------------

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = 0;

        while(numBottles >= numExchange){
            consumed += numExchange;
            numBottles -= numExchange;

            numBottles += 1;
        }

        return (numBottles + consumed);
    }
};

// ------------------------------------- Approach - 3 -------------------------------------------

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};