// ----------------------------- Approach - 1 -----------------------------------
// Recursion + Memoization

class Solution {
public:
    int t[1001][1001];
    int solve(int currA, int clipA, int n){
        if(currA == n){
            return 0;
        }
        if(currA > n){
            return 100000;
        }
        if(t[currA][clipA] != -1){
            return t[currA][clipA];
        }

        int copyPasteAll = 1 + 1 + solve(currA + currA, currA, n);

        int paste = 1 + solve(currA + clipA, clipA, n);

        return t[currA][clipA] = min(copyPasteAll, paste);
    }

    int minSteps(int n) {
        if(n == 1){
            return 0;
        }

        memset(t, -1, sizeof(t));

        return 1 + solve(1, 1, n);
    }
};

// ----------------------------- Approach - 2 -----------------------------------
// Bottom-up Approach

class Solution {
public:
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        if(n == 2){
            return 2;
        }

        vector<int> t(n+1, 0);
        t[0] = 0;
        t[1] = 0;
        t[2] = 2;

        for(int i = 3; i <= n; i++){
            int factor = i/2;
            while(factor >= 1){
                if(i%factor == 0){
                    int steps_to_print_factor_as = t[factor];
                    int copy = 1;
                    int paste = (i / factor) - 1;

                    t[i] = steps_to_print_factor_as + copy + paste;
                    break;
                } else {
                    factor--;
                }
            }
        }


        return t[n];
    }
};

