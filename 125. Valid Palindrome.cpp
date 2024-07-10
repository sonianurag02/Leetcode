// -------------------------- Approach - 1 --------------------------

class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                str+= tolower(s[i]);
            }
        }
        int right=str.length()-1;
        for(int i=0;i<str.length()/2;i++){
            if(str[i]!=str[right]) return false;
            right--;
        }
        return true;
    }
};