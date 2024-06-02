// -------------- Approach - 1 (Using Loops) ------------

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i = 0, j = n-1;
        while(i < j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            i++;
            j--;
        }
    }
};

// ------- Approach - 2 (Using in-built function) -------

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

// ---------- Approach - 3 (Using swap function) --------

class Solution {
public:
    void reverseString(vector<char>& s) {
        int u=s.size()-1;
        for(int i=0;i<s.size()/2;i++){
            swap(s[i],s[u]);
            u--;
        }
    }
};