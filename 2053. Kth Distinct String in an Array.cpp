// ------------------------------ Approach - 1 ------------------------------
// Brute force

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        vector<string> distinct;

        for(int i = 0; i < n; i++){
            string currStr = arr[i];
            bool isDistinct = true;

            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(arr[j] == currStr){
                    isDistinct = false;
                    break;
                }
            }

            if(isDistinct){
                distinct.push_back(currStr);
            }
        }

        if(distinct.size() < k){
            return "";
        }

        return distinct[k-1];
    }
};

// --------------------------------- Approach - 2 ------------------------------
// Using map

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        for(auto& str: arr){
            mp[str]++;
        }

        for(auto& str: arr){
            if(mp[str] == 1){
                k--;
            }
            if(k == 0){
                return str;
            }
        }

        return "";
    }
};