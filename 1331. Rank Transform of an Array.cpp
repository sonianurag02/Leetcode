// ----------------------------- Approach - 1 ----------------------------
// Ordered Map

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> mp;

        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]].push_back(i);
        }

        int rank = 1;
        for(auto& pair: mp){
            for(int idx: pair.second){
                arr[idx] = rank;
            }
            rank++;
        }
        
        return arr;
    }
};

// ----------------------------- Approach - 1 ----------------------------
// Using Vector

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> brr(n);

        for(int i = 0; i < n; i++){
            brr[i] = {arr[i], i};
        }

        sort(brr.begin(), brr.end());

        vector<int> res(n);

        for(int i = 0; i < n; i++){
            if(i == 0) res[brr[i].second] = 1;
            else{
                if(brr[i].first == brr[i-1].first){
                    res[brr[i].second] = res[brr[i-1].second];
                } else {
                    res[brr[i].second] = res[brr[i-1].second] + 1;
                }
            }
        }

        return res;
    }
};