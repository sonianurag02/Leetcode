// ------------------------------- Code ---------------------------------------

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string str1 = strs[0];
        string str2 = strs[strs.size() - 1];
        int idx = 0;

        while(idx < str1.size()){
            if(str1[idx] == str2[idx]){
                idx++;
            }
            else break;
        }

        return idx == 0 ? "" : str1.substr(0, idx);
    }
};