// ---------------------------------- Approach - 1 ------------------------------------------

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res;

        for(char& ch: s){
            if(ch == '('){
                st.push(res.length());
            }
            else if(ch == ')'){
                int start = st.top();
                st.pop();
                reverse(res.begin() + start, res.end());
            }
            else{
                res += ch;
            }
        }

        return res;
    }
};