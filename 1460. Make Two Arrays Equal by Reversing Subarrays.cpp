// --------------------------------- Approach - 1 ---------------------------------------
// Brute Force

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int m = target.size();
        int n = arr.size();

        if(m != n) return false;

        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; i++){
            if(target[i] != arr[i]){
                return false;
            }
        }

        return true;
    }
};

// --------------------------------- Approach - 2 ---------------------------------------
// Using unordered map

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> arrFreq;
        for(int num: arr){
            arrFreq[num]++;
        }

        unordered_map<int, int> targetFreq;
        for(int num: target){
            targetFreq[num]++;
        }

        if(arrFreq.size() != targetFreq.size()){
            return false;
        }

        for(auto it: arrFreq){
            if(targetFreq[it.first] != it.second){
                return false;
            }
        }

        return true;
    }
};

// --------------------------------- Approach - 3 ---------------------------------------

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> arrFreq;
        for(int num: arr){
            arrFreq[num]++;
        }

        for(int num: target){
            if(arrFreq.find(num) == arrFreq.end()){
                return false;
            }

            arrFreq[num]--;

            if(arrFreq[num] == 0){
                arrFreq.erase(num);
            }
        }

        return arrFreq.size() == 0;
    }
};