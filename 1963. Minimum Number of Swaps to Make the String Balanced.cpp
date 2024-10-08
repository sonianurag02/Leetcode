// --------------------------------- Approach - 1 --------------------------------------------
// Using stack

class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(char& ch: s){
            if(ch == '['){
                st.push(ch);
            } else if(!st.empty()){
                st.pop(); // Balancing closing bracket ] with an open bracket in the stack
            }
        }

        // Size of stack = number of opening brackets
        return (st.size()+1) / 2;
    }
};

// --------------------------------- Approach - 2 --------------------------------------------
// Using O(1) space

class Solution {
public:
    int minSwaps(string s) {
        // stack<char> st;
        int size = 0;

        for(char& ch: s){
            if(ch == '['){
                // st.push(ch);
                size++;
            } else if(size > 0){ //!st.empty()
                // st.pop(); // Balancing closing bracket ] with an open bracket in the stack
                size--;
            }
        }

        // Size of stack = number of opening brackets
        return (size+1) / 2;
    }
};