// --------------------- Approach - 1 ----------------------------------------

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        
        for(char& ch: s){
            mp[ch]++;
        }

        int count = 0;
        int result = 0;

        for(auto& i: mp){
            if(i.second % 2 == 0){
                result += i.second;
            }
            else{
                result += i.second - 1;
                count++;
            }
        }

        return (count > 0) ? result + 1 : result;
    }
};

// --------------------- Approach - 2 ----------------------------------------

class Solution {
public:
    int longestPalindrome(string s) {
        int oddFreq = 0;
        unordered_map<char, int> mp;
        
        for(char& ch: s){
            mp[ch]++;

            if((mp[ch] % 2) == 1){
                oddFreq++;
            }
            else{
                oddFreq--;
            }
        }

        if(oddFreq > 0){
            return s.length() - oddFreq + 1;
        }
        else{
            return s.length();
        }
    }
};