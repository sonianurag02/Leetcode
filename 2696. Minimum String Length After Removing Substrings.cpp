// --------------------------- Approach - 1 --------------------------------------
// Using Stack

class Solution {
public:
    int minLength(string s) {
        stack<int> st;

        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && (((st.top() == 0) && (s[i] - 'a' + 32 == 1)) || ((st.top() == 2) && (s[i] - 'a' + 32 == 3)))){
                cout<<st.top()<<" ";
                st.pop();
                continue;
            }
            st.push(s[i] - 'a' + 32);
            cout<<st.top()<<" ";
        }   

        return st.size();
    }
};

// --------------------------- Approach - 2 --------------------------------------

class Solution {
public:
    int minLength(string s) {
        int n = s.length();

        int i = 0; // Read
        int j = 1; // Write

        while(j < n){
            if(i < 0){
                i++;
                s[i] = s[j];
            } else if((s[i] == 'A' && s[j] == 'B') || (s[i] == 'C' && s[j] == 'D')){
                i--;
            } else {
                i++;
                s[i] = s[j];
            }

            j++;
        }

        return i+1;
    }
};