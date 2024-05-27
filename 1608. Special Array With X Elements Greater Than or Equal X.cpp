// ------------------------------------ Approach - 1 --------------------------------------------------

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        for(int x = 0; x <= n; x++){
            // pointer to first element >= x
            int idx = lower_bound(begin(nums), end(nums), x) - begin(nums);

            int count = n - idx;

            if(count == x) return x;
        }
        return -1;
    }
};

// ------------------------------------ Approach - 2 --------------------------------------------------

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int l = 0, r = n;

        for(int x = 0; x <= n; x++){
            int mid_x = l + (r-l)/2;
            // pointer to first element >= x
            int idx = lower_bound(begin(nums), end(nums), mid_x) - begin(nums);
            int count = n - idx;

            if(count == mid_x) return mid_x;

            else if(count > mid_x) l = mid_x + 1;

            else r = mid_x - 1;
        }
        return -1;
    }
};

// ------------------------------------ Approach - 3 (Cumulative Sum) -----------------------------------

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1);

        for(int i = 0; i < n; i++){
            int num = nums[i];

            freq[min(n, num)]++;
        }

        int cum_sum = 0;
        for(int x = n; x >= 0; x--){
            cum_sum += freq[x];

            if(x == cum_sum) return x;
        }
        
        return -1;
    }
};