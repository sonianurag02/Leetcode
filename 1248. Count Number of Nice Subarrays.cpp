// ------------------------------- Approach - 1 (Using Hash Map) -------------------------------------

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int result = 0;
        int oddCount = 0;
        mp[oddCount] = 1;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            oddCount += (nums[i]%2);

            if(mp.count(oddCount - k)){
                result += mp[oddCount - k];
            }

            mp[oddCount]++;
        }

        return result;
    }
};

// ------------------------------- Approach - 2 (Using Sliding Window) -------------------------------------

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        int oddCount = 0;
        int prevCount = 0;
        int result = 0;

        int i = 0;
        int j = 0;

        while(j < n){
            if(nums[j] % 2 != 0){
                oddCount++;
                prevCount = 0;
            }

            while(oddCount == k){
                prevCount++;

                if(i < n && nums[i]%2 == 1){
                    oddCount--;
                }
                i++;
            }

            result += prevCount;
            j++;
        }

        return result;
    }
};