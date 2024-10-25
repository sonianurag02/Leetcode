// --------------------------- Approach - 1 ----------------------------------
// Bit Manipulation

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        for(int i = 31; i >= 0; i--){
            if(((n >> i) & 1) == 1) {
                count++;
            }
        }

        return count;
    }
};

// --------------------------- Approach - 2 ----------------------------------

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while(n){
            n = (n & (n-1)); // Unsetting the right most set bit
            count++;
        }

        return count;
    }
};

// --------------------------- Approach - 3 ----------------------------------

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while(n){
            count += (n % 2);
            n = n / 2;
        }

        return count;
    }
};

// --------------------------- Approach - 4 ----------------------------------

class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};