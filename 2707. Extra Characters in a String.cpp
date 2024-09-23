// ------------------------------ Approach - 1 ---------------------------
// Brute Force - Recursion
// TLE

class Solution {
public:
    int solve(int i, string& s, unordered_set<string>& st, int n){
        if(i >= n){
            return 0;
        }

        int result = 1 + solve(i+1, s, st, n);


        for(int j = i; j < n; j++){
            string str = s.substr(i, j-i+1);
            if(st.count(str)){
                result = min(result, solve(j+1, s, st, n));
            }
        }

        return result;
    }

    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(begin(dict), end(dict));

        return solve(0, s ,st, n);
    }
};

// ------------------------------ Approach - 2 ---------------------------
// Recursion + Memoization

class Solution {
public:
    int t[51];
    int solve(int i, string& s, unordered_set<string>& st, int n){
        if(i >= n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        int result = 1 + solve(i+1, s, st, n);


        for(int j = i; j < n; j++){
            string str = s.substr(i, j-i+1);
            if(st.count(str)){
                result = min(result, solve(j+1, s, st, n));
            }
        }

        return t[i] = result;
    }

    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        unordered_set<string> st(begin(dict), end(dict));

        return solve(0, s ,st, n);
    }
};

// ------------------------------ Approach - 3 ---------------------------

class Solution {
public:
    int t[51];
    int solve(int i, string& s, unordered_set<string>& st, int n, unordered_map<int, int>& mp){
        if(i >= n){
            return 0;
        }

        if(mp.count(i)){
            return mp[i];
        }

        int result = 1 + solve(i+1, s, st, n, mp);


        for(int j = i; j < n; j++){
            string str = s.substr(i, j-i+1);
            if(st.count(str)){
                result = min(result, solve(j+1, s, st, n, mp));
            }
        }

        return mp[i] = result;
    }

    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        unordered_map<int, int> mp;
        unordered_set<string> st(begin(dict), end(dict));

        return solve(0, s ,st, n, mp);
    }
};

// ------------------------------ Approach - 4 ---------------------------
// Bottom up Approach

class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(begin(dict), end(dict));

        vector<int> t(n+1, 0);

        for(int i = n-1; i >= 0; i--){
            t[i] = 1 + t[i+1];

            for(int j = i; j < n; j++){
                string curr = s.substr(i, j-i+1);
                if(st.count(curr)){
                    t[i] = min(t[i], t[j+1]);
                }
            }
        }

        return t[0];
    }
};