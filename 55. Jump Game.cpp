// ---------------------------- Approach - 1 (Recursion + Memoization) --------------------------------

class Solution {
public:
    int t[10001];

    bool solve(vector<int>& nums, int k, int idx){
        if(idx == k-1){
            return true;
        }

        if(t[idx] != -1) return t[idx];

        for(int i = 1; i <= nums[idx]; i++){
            if(solve(nums, k, idx+i) == true){
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int k = nums.size();
        memset(t, -1, sizeof(t));

        return solve(nums, k, 0);
    }
};

// ------------------------------------- Approach - 2 (Bottum-up) -----------------------------------

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> t(n, false);
        t[0] = true;

        for(int i = 1; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(t[j] == true && j + nums[j] >= i){
                    t[i] = true;
                    break;
                }
            }
        }
        return t[n-1];
    }
};

// ------------------------------------- Approach - 3 (Optimized approach) -----------------------------------

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxReachable = 0;

        for(int i = 0; i < n; i++){
            if(i > maxReachable){
                return false;
            }

            maxReachable = max(maxReachable, i + nums[i]);
        }

        return true;
    }
};