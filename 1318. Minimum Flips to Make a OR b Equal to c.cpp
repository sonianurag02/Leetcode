// ------------------------- Approach - 1 ----------------------------------------

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while(a != 0 || b != 0 || c != 0){
            if( (c & 1) == 1){ // Right most bit == 1
                if((a & 1) == 0 && (b & 1) == 0) flips++;
            }
            else{
                if((a & 1) == 1) flips++;
                if((b & 1) == 1) flips++;

                // flips += (a&1) + (b&1);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};

// ------------------------- Approach - 1 ----------------------------------------

class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcount((a|b) ^ c) + __builtin_popcount((a&b) & ((a|b)^c));
    }
};