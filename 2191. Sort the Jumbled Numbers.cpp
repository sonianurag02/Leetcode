// ---------------------------------- Approach - 1 ------------------------------

#include <cstdlib>
class Solution {
public:
    string getMappedNum(string& str, vector<int>& mapping){
        string mappedNum = "";

        for(int i = 0; i < str.size(); i++){
            char ch = str[i];
            int idx = ch - '0';
            mappedNum += to_string(mapping[idx]);
        }

        return mappedNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++){
            string str = to_string(nums[i]);

            string mappedStr = getMappedNum(str, mapping);

            int mappedNum = stoi(mappedStr);

            vec.push_back({mappedNum, i});
        }

        sort(begin(vec), end(vec));

        vector<int> res;

        for(auto& i: vec){
            int originalIdx = i.second;
            res.push_back(nums[originalIdx]);
        }

        return res;
    }
};

// ---------------------------------- Approach - 2 ------------------------------

#include <cstdlib>
class Solution {
public:
    int getMappedNum(int num, vector<int>& mapping){
        if(num < 10){
            return mapping[num];
        }

        int mappedNum = 0;
        int placeVal = 1;

        while(num > 0){
            int lastDigit = num % 10;
            int mappingDigit = mapping[lastDigit];

            mappedNum += (mappingDigit * placeVal);

            placeVal *= 10;
            num /= 10;
        }

        return mappedNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++){
            int mappedNum = getMappedNum(nums[i], mapping);

            vec.push_back({mappedNum, i});
        }

        sort(begin(vec), end(vec));

        vector<int> res;

        for(auto& i: vec){
            int originalIdx = i.second;
            res.push_back(nums[originalIdx]);
        }

        return res;
    }
};