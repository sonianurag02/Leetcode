// ---------------------- Approach - 1 ---------------------------

class Solution {
public:
    bool ismatching(char a, char b){
        return ((a == ')' && b == '(' || a == '}' && b == '{' || a == ']' && b == '['));
    }
    bool isValid(string s) {
        stack<char> sc;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') 
                sc.push(s[i]);
            else {
                if(sc.empty()){
                    return false;
                }
                if(ismatching(s[i], sc.top())){
                    sc.pop();
                }
                else return false; 
            }
        }
        if(sc.empty()){
            return true;
        }
        return false;
    }
};