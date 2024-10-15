// ----------------------------- Approach - 1 -------------------------------

class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps = 0;

        long long black = 0;

        for(int i = 0; i < s.length(); i++){   
            if(s[i] == '0'){
                swaps += black;
            } else {
                black++;
            }
        }

        return swaps;
    }
};

// ----------------------------- Approach - 2 -------------------------------

class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps = 0;

        int white = 0;

        for(int i = s.length() - 1; i >= 0; i--){   
            if(s[i] == '0'){
                white++;
            } else {
                swaps += white;
            }
        }

        return swaps;
    }
};