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

// ---------------------------- Approach - 2 ------------------------------
// Using Stack (Better one)

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(auto ch : expression) {
            if(ch == ',' || ch == '(') continue;

            if(ch == '|' || ch == '!' || ch == '&' || ch == 'f' || ch == 't'){
                st.push(ch);
            }
            else if(ch == ')') {
                bool hasTrue = false, hasFalse = false;
                while(st.top() != '!' && st.top() != '|' && st.top() != '&')  {
                    char curTop = st.top();
                    st.pop();
                    if(curTop == 'f') hasFalse = true;
                    if(curTop == 't') hasTrue = true;
                }

                char op = st.top();
                st.pop();
                if(op == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if(op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};
