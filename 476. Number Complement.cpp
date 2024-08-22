// ---------------------------- Approach - 1 -------------------------------
// Brute Force

class Solution {
public:
    int findComplement(int num) {
        string bin = "";

        while(num > 0){
            int rem = num % 2;
            bin += to_string(rem);
            num /= 2;
        }
        reverse(begin(bin), end(bin));

        int n = bin.size();
        for(int i = 0; i < n; i++){
            if(bin[i] == '0'){
                bin[i] = '1';
            } else if(bin[i] == '1') {
                bin[i] = '0';
            }
        }
        int res = 0;
        int j = 0;

        for(int i = n-1; i >= 0; i--, j++){
            res += ((int)bin[i]-48) * pow(2, j);
        }

        return res;
    }
};

// ---------------------------- Approach - 2 -------------------------------
// Bit Manipulation

class Solution {
public:
    int findComplement(int num) {
        int numBits = (int)(log2(num)) + 1;

        for(int i = 0; i < numBits; i++){
            num = num ^ (1<<i);
        }

        return num;
    }
};

// ---------------------------- Approach - 3 -------------------------------

class Solution {
public:
    int findComplement(int num) {
        int numBits = (int)(log2(num)) + 1;

        unsigned int mask = (1U << numBits) - 1;

        return num ^ mask;
    }
};

// ---------------------------- Approach - 4 -------------------------------

class Solution {
public:
    int findComplement(int num) {
        int i = 0;
        int compliment = 0;

        while(num){
            if(!(num & 1)){ // if it's a 0, then we need to flip it
                compliment |= (1 << i);
            }

            num >>= 1; // right shifting num
            i++;
        }

        return compliment;
    }
};