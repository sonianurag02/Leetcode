// ------------------ Approach - 1 (Brute Force - Hash map) ------------------------------

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(int num: nums){
            mp[num]++;
        }
        for(auto& i: mp){
            int x = i.first;
            int y = i.second;
            if(y == 1){
                res.push_back(x);
            }
        }
        return res;
    }
};

// --------------------------------- Approach - 2 -------------------------------------------

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2);
        int index = 0;

        for(int i = 0; i < n; i++){
            bool found = false;
            for(int j = 0; j < n; j++){
                if(i != j && nums[i] == nums[j]){
                    found = true;
                    break;
                }
            }
            if(!found){
                res[index++] = nums[i];
                if(index == 2) break;
            }
        }
        return res;
    }
};

// ------------------------- Approach - 3 (Bit Manipulation - XOR Operation) ------------------

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_r = 0;

        for(int &num: nums){
            xor_r ^= num;
        }

        int mask = (xor_r) & (-xor_r);

        int groupA = 0;
        int groupB = 0;

        for(int &num: nums){
            if(num & mask){
                groupA ^= num;
            }
            else groupB ^= num;
        }

        return {groupA, groupB};
    }
};