// -------------------------------------- Approach - 1 -----------------------------------

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map <int,int> a;
        int n = nums.size();

        for (int i = 0; i < n; i++){
            if(a.count(nums[i])){
                if(abs(i - a[nums[i]]) <= k){
                    return true;
                }
            }
            a[nums[i]] = i;
        }
        return false;
    }
};