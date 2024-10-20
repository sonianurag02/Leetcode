// ---------------------------- Approach - 1 ------------------------------
// Using Stack

class Solution {
public:
    char solveOperator(vector<char>& values, char op){
        if(op == '!'){
            return values[0] == 't' ? 'f' : 't';
        }

        // Handle &
        if(op == '&'){
            return any_of(begin(values), end(values), [](char ch) {return ch == 'f';}) ? 'f' : 't';
        }

        // Handle |
        if(op == '|'){
            return any_of(begin(values), end(values), [](char ch) {return ch == 't';}) ? 't' : 'f';
        }

        return 't'; // will never come here
    }

    bool parseBoolExpr(string expression) {
        int n = expression.size();

        stack<int> st;

        for(int i = 0; i < n; i++){
            if(expression[i] == ','){
                continue;
            } else if(expression[i] == ')'){
                vector<char> values;

                while(st.top() != '('){
                    values.push_back(st.top());
                    st.pop();
                }

                st.pop();
                char op = st.top(); // &, |, !
                st.pop();

                st.push(solveOperator(values, op));
            } else {
                st.push(expression[i]);
            }
        }

        return st.top() == 't' ? true : false;
    }
};