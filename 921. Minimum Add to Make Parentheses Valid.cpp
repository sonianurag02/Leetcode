// -------------------------- Approach - 1 ----------------------------------------
// Using Stack

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        int count_a = 0;
        int count_b = 0;

        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
                count_a--;
            } else if(s[i] == '('){
                st.push(s[i]);
                count_a++;
            } else {
                count_b++;
            }
        }

        return count_a + count_b;
    }
};

// -------------------------- Approach - 2 ----------------------------------------

class Solution {
public:
    int minAddToMakeValid(string s) {
        int size = 0;
        int open = 0;

        for(char& ch: s){
            if(ch == '('){
                size++;
            } else if(size > 0){
                size--;
            } else {
                open++;
            }
        }

        return open + size;
    }
};