// ------------------- Approach - 1 (Using Stack) ------------------------

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for(string& str: logs){
            if(str == "../"){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(str != "./"){
                st.push(str);
            }
        }

        return st.size();
    }
};

// ------------------- Approach - 1 (Using Stack) ------------------------

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for(auto& str: logs){
            if(str == "../"){
                depth = max(0, depth - 1);
            }
            else if(str != "./"){
                depth++;
            }
        }

        return depth;
    }
};