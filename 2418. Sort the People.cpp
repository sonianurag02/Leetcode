// ----------------------------- Approach - 1 (Brute Force) ------------------------

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        vector<string> res;
        map<int, string> mp;

        for(int i = 0; i < n; i++){
            mp[heights[i]] = names[i];
        }

        for(auto& i: mp){
            res.push_back(i.second);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

// ----------------------------- Approach - 2 (vector pair) ------------------------ 

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();

        vector<pair<int, string>> vec;
        
        for(int i = 0; i < n; i++){
            vec.push_back({heights[i], names[i]});
        }

        sort(vec.rbegin(), vec.rend());

        vector<string> res;
        for(auto& i: vec){
            res.push_back(i.second);
        }

        return res;
    }
};