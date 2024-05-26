// ---------------------------- Recursion + Memoization ------------------------------------

class Solution {
public:
    int t[100001][2][3];
    int M = 1e9 + 7;

    int solve(int n, int absent, int consLate){
        if(absent > 1 || consLate > 2) return 0;

        if(n == 0) return 1;

        if(t[n][absent][consLate] != -1) return t[n][absent][consLate];

        int abs = solve(n-1, absent+1, 0) % M; // Absent Count
        int consecutiveLate = solve(n-1, absent, consLate+1) % M; // Consecutive Late count
        int pres = solve(n-1, absent, 0) % M; // Present Count

        return t[n][absent][consLate] = ((abs + consecutiveLate) % M + pres) % M;
    }
    int checkRecord(int n) {
        memset(t, -1, sizeof(t));

        return solve(n, 0, 0);
    }
};

// ----------------------------- Bottom-up Approach ---------------------------------------

class Solution {
public:
    int M = 1e9 + 7;
    int checkRecord(int n) {
        int t[100001][2][3];

        // Base Case (n == 0)
        for(int A = 0; A <= 1; A++){
            for(int L = 0; L <= 2; L++){
                t[0][A][L] = 1;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int A = 0; A <= 1; A++){
                for(int L = 0; L <= 2; L++){
                    long result = t[i-1][A][0]; // solve(n-1, abs, 0)
                    result += (L+1 <= 2 ? t[i-1][A][L+1] : 0); // solve(n-1, abs, L+1)
                    result += (A+1 <= 1 ? t[i-1][A+1][0] : 0); // solve(n-1, aba+1, 0)

                    t[i][A][L] = result % M;
                }
            }
        }

        return t[n][0][0]; // solve(n, 0, 0);
    }
};