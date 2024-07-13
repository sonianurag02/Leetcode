// --------------------------- Approach - 1 -------------------------------

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n), res;
        stack<int> st;

        for(int i = 0; i < n; i++){
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(),
            [&](int lhs, int rhs){return positions[lhs] < positions[rhs]; });

        for(int currentIdx : indices){
            if(directions[currentIdx] == 'R'){
                st.push(currentIdx);
            }
            else{
                while(!st.empty() && healths[currentIdx] > 0){
                    int topIdx = st.top();
                    st.pop();

                    if(healths[topIdx] > healths[currentIdx]){
                        healths[topIdx] -= 1;
                        healths[currentIdx] = 0;
                        st.push(topIdx);
                    }
                    else if(healths[topIdx] < healths[currentIdx]){
                        healths[currentIdx] -= 1;
                        healths[topIdx] = 0;
                    }
                    else{
                        healths[currentIdx] = 0;
                        healths[topIdx] = 0;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(healths[i] > 0){
                res.push_back(healths[i]);
            }
        }

        return res;
    }
};