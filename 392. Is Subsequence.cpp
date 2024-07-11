// ---------------------------- Approach - 1 -------------------------------

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();

        map<char, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[t[i]].push_back(i);
        }

        int prev = -1;

        for(int i = 0; i < m; i++){
            char ch = s[i];

            if(mp.find(ch) == mp.end()) return false;

            vector<int> indices = mp[ch];

            auto it = upper_bound(begin(indices), end(indices), prev);

            if(it == indices.end()) return false;

            prev = *it;
        }

        return true;
    }
};

// ---------------------------- Approach - 2 -------------------------------

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();

        stack<int> openBracketIndex;
        vector<int> door(n);

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                openBracketIndex.push(i);
            }
            else if(s[i] == ')'){
                int j = openBracketIndex.top();
                openBracketIndex.pop();
                door[j] = i;
                door[i] = j;
            }
        }

        string result;
        int flag = 1;
        for(int i = 0; i < n; i += flag){
            if(s[i] == '(' || s[i] == ')'){
                i = door[i];
                flag = -flag;
            }
            else{
                result.push_back(s[i]);
            }
        }

        return result;
    }
};
