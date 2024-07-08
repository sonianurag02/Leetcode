// ------------------------- Approach - 1 (Using Hash Map) ------------------------------

class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(false);
        
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> mp;

        for(char& ch: s){
            mp[ch]++;
        }
        for(char& ch: t){
            mp[ch]--;
        }

        for(auto i: mp){
            if(i.second != 0){
                return false;
            }
        }

        return true;
    }
};

// --------------------------------- Approach - 2 (sorting) ------------------------------

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};