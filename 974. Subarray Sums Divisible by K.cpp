// -------------------------- Approach - 1 (Brute Force 1) TLE -----------------------------------------

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        long long sum = nums[0];
        int i = 0, j = 0;
        int n = nums.size();
        int count = 0;

        while(i < n){
            if(sum % k == 0){
                count++;
            }
            if(j == n-1){
                i++;
                j = i;
                sum = nums[i];
                continue;
            }
            j++;
            sum += nums[j];
        }

        return count;
    }
};

// -------------------------- Approach - 2 (Brute Force 2) TLE -----------------------------------------

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        int result = 0;

        for(int i = 1; i < n; i++){
            nums[i] += nums[i-1];
        }

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = (i == 0) ? nums[j] : nums[j] - nums[i-1];

                if(sum % k == 0){
                    result++;
                }
            }
        }
        return result;
    }
};

// -------------------------- Approach - 3 (Optimal Approach) -----------------------------------------

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        mp[0] = 1;
        
        int sum = 0;
        int result = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            int rem = sum % k;

            if(rem < 0){
                rem += k;
            }

            if(mp.find(rem) != mp.end()){
                result += mp[rem];
            }

            mp[rem]++;
        }

        return result;
    }
};