// --------------------------------- Approach - 1 --------------------------------
// Recursion

class Solution {
public:
    int n;
    vector<vector<int>> t;

    int solve(int l, int r, string& s){
        if(l == r){
            return 1;
        }
        else if(l > r){
            return 0;
        }

        if(t[l][r] != -1){
            return t[l][r];
        }

        int i = l+1;
        while(i <= r && s[i] == s[l]){
            i++;
        }
        if(i == r+1){
            return 1;
        }
        int basic = 1 + solve(i, r, s);

        int lalach = INT_MAX;
        for(int j = i; j <= r; j++){
            if(s[l] == s[j]){
                int ans = solve(i, j-1, s) + solve(j, r, s);
                lalach = min(lalach, ans);
            }
        }

        return t[l][r] = min(basic, lalach);
    }

    int strangePrinter(string s) {
        n = s.length();
        t.resize(n+1, vector<int>(n+1, -1));

        return solve(0, n-1, s);
    }
};