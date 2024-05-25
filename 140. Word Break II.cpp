//------------------------------ Backtracking ------------------------

class Solution {
public:
    void solve(int i, string& currSentence, string& s, vector<string>& result, unordered_set<string>& st){
        if(i >= s.length()){
            result.push_back(currSentence);
            return;
        }

        for(int j = i; j < s.size(); j++){
            string tempWord = s.substr(i, j-i+1);

            if(st.count(tempWord)){ // valid word
                string tempSentence = currSentence;
                if(!currSentence.empty()){
                    currSentence += " ";
                }
                currSentence += tempWord; // Take tempword

                solve(j+1, currSentence, s, result, st); // Explore

                currSentence = tempSentence; // Remove tempWord
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        unordered_set<string> st;

        for(string& word: wordDict){
            st.insert(word);
        }

        string currSentence = "";

        solve(0, currSentence, s, result, st);

        return result;
    }
};

// ------------------------- Recursion -------------------------------------

class Solution {
public:
    vector<string> solve(string& s, unordered_set<string>& st){
        if(s.empty()){
            return {""};
        }
        vector<string> result;
        for(int l = 1; l <= s.size(); l++){
            string currWord = s.substr(0, l);
            if(st.count(currWord)){
                string remainWord = s.substr(l);
                vector<string> remainResult = solve(remainWord, st);
                for(string& w: remainResult){
                    string toAdd = currWord + (w.empty() ? "" : " ") + w;
                    result.push_back(toAdd);
                }
            }
        }
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;

        for(string& word: wordDict){
            st.insert(word);
        }

        return solve(s, st);
    }
};

// -------------------- Recursion + Memoization ---------------------

class Solution {
public:
    unordered_map<string, vector<string>> mp;

    vector<string> solve(string& s, unordered_set<string>& st){
        if(s.empty()){
            return {""};
        }

        if(mp.count(s)){
            return mp[s];
        }

        vector<string> result;
        for(int l = 1; l <= s.size(); l++){
            string currWord = s.substr(0, l);
            if(st.count(currWord)){
                string remainWord = s.substr(l);
                vector<string> remainResult = solve(remainWord, st);
                for(string& w: remainResult){
                    string toAdd = currWord + (w.empty() ? "" : " ") + w;
                    result.push_back(toAdd);
                }
            }
        }
        return mp[s] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;

        for(string& word: wordDict){
            st.insert(word);
        }

        return solve(s, st);
    }
};