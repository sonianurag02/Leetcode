// ------------------ Approach - 1 (Using Hash Map) ------------------------

class Solution {
public:
    string findWord(string& word,  unordered_set<string>& st){
        for(int l = 1; l <= word.length(); l++){
            string root = word.substr(0, l);
            if(st.count(root)){
                return root;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(begin(dictionary), end(dictionary));

        stringstream ss((sentence));
        string word;
        string result;

        while(getline(ss, word, ' ')){
            result += findWord(word, st) + " ";
        }

        result.pop_back();
        return result;
    }
};

// --------------------- Approach - 1 (Using Trie) ---------------------------

class Solution {
public:
    struct Trie {
        Trie* ch[26] = {};
        bool end = false;

        void insert(const string& s, int p) {
            if (p < s.length()) {
                int idx = s[p] - 'a';
                if (ch[idx] == nullptr)
                    ch[idx] = new Trie();
                if (ch[idx]->end)
                    return;
                ch[idx]->insert(s, p + 1);
            }
            else
                end = true;
        }

        bool find(const string& s, int p, string& ret) {
            if (p == s.length()) {
                ret = s;
                return end;
            }

            int idx = s[p] - 'a';
            if (ch[idx] != nullptr) {
                if (ch[idx]->end) {
                    ret = s.substr(0, p+1);
                    return true;
                }
                else
                    return ch[idx]->find(s, p + 1, ret);
            }
            else {
                ret = s;
                return false;
            }
        }
    };

    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for (string diction : dictionary) {
            t.insert(diction, 0);
        }
        string ans;
        stringstream str(sentence);
        string word;
        while (str >> word) {
            string res;
            t.find(word, 0, res);
            ans += res + " ";
        }
        ans.pop_back();
        return ans;
    }
};