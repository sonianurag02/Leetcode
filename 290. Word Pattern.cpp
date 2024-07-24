// ------------------------- Approach - 1 (Using map and set) -------------------------

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;

        stringstream ss(s);
        string word;
        int count = 0;

        while(getline(ss, word, ' ')){
            vec.push_back(word);
            count++;
        }

        int n = pattern.size();

        if(count != n){
            return false;
        }
        
        unordered_map<string, char> mp;
        set<char> used;
        
        for(int i = 0; i < n; i++){
            string word = vec[i];
            char ch = pattern[i];

            if(mp.find(word) == mp.end() && used.find(ch) == used.end()){
                used.insert(ch);
                mp[word] = ch;
            } else if(mp[word] != pattern[i]){
                return false;
            }
        }

        return true;
    }
};

// --------------------------- Approach - 2 (Map of index. char to i+1) --------------------

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> charToIndex;
        unordered_map<string, int> wordToIndex;

        stringstream ss(s);
        string tokens;

        int countTokens = 0;
        int i = 0;
        int n = pattern.size();


        while(ss >> tokens){
            countTokens++;

            if(i == n || charToIndex[pattern[i]] != wordToIndex[tokens])
                return false;

            charToIndex[pattern[i]] = i+1;
            wordToIndex[tokens] = i+1;
            
            i++;
        }

        if(i != n || countTokens != n)
            return false;
        
        return true;
    }
};