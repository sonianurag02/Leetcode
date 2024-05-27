// ----------------- Approach - 1 (Recursion + memoization) -----------------

class Solution {
public:
    int m, n;
    int t[501][501];
    int solve(string& s1, string& s2, int i, int j){
        if(i == m){
            return n - j; // Insertion in s1
        }
        else if(j == n){
            return m - i; // Deletion from s1
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(s1[i] == s2[j]){
            return t[i][j] = solve(s1, s2, i+1, j+1);
        }
        else{
            int ins = 1 + solve(s1, s2, i, j+1);
            int del = 1 + solve(s1, s2, i+1, j);
            int rep = 1 + solve(s1, s2, i+1, j+1);

            return t[i][j] = min({ins, rep, del}); 
        }
        return -1;
    }

    int minDistance(string s1, string s2) {
        m = s1.size();
        n = s2.size();

        memset(t, -1, sizeof(t));

        return solve(s1, s2, 0, 0);
    }
};

// ----------------- Approach - 1 (Recursion + memoization) -----------------
// Starting from last index

class Solution {
public:
    int m, n;
    int t[501][501];
    int solve(string& s1, string& s2, int m, int n){
        if(m == 0 || n == 0){
            return m + n;
        }
        if(t[m][n] != -1){
            return t[m][n];
        }
        if(s1[m - 1] == s2[n - 1]){
            return t[m][n] = solve(s1, s2, m-1, n-1);
        }
        else{
            int ins = 1 + solve(s1, s2, m, n-1);
            int del = 1 + solve(s1, s2, m-1, n);
            int rep = 1 + solve(s1, s2, m-1, n-1);

            return t[m][n] = min({ins, rep, del}); 
        }
        return -1;
    }

    int minDistance(string s1, string s2) {
        m = s1.size();
        n = s2.size();

        memset(t, -1, sizeof(t));

        return solve(s1, s2, m, n);
    }
};

// ----------------------- Bottom-up Approach ---------------------------------------

class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> t(m+1, vector<int>(n+1));

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    t[i][j] = i+j;
                }
                else if(s1[i-1] == s2[j-1]){
                    t[i][j] = t[i-1][j-1];
                }
                else{
                    t[i][j] = 1 + min({t[i][j-1], t[i-1][j], t[i-1][j-1]});
                }
            }
        }

        return t[m][n];
    }
};