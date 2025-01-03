// --------------------------------------- Approach - 1 ---------------------------------------

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int consistentCount = 0;

        for(string& word: words){
            bool isWordConsistent = true;

            for(int i = 0; i < word.length(); i++){
                char currChar = word[i];
                bool isCharAllowed = false;

                for(int j = 0; j < allowed.length(); j++){
                    if(allowed[j] == currChar){
                        isCharAllowed = true;
                        break;
                    }
                }

                if(!isCharAllowed){
                    isWordConsistent = false;
                    break;
                }
            }

            if(isWordConsistent){
                consistentCount++;
            }
        }

        return consistentCount;
    }
};
