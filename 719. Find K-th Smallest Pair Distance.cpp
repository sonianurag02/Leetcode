// -------------------------------- Approach - 1 -------------------------------

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEl = *max_element(begin(nums), end(nums));
        vector<int> vec(maxEl+1, 0);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int d = abs(nums[i] - nums[j]);
                vec[d]++;
            }
        }

        for(int d = 0; d < maxEl+1; d++){
            k -= vec[d];
            if(k <= 0){
                return d;
            }
        }

        return -1;
    }
};

// -------------------------------- Approach - 2 -------------------------------

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vec(n*(n-1)/2);

        int idx = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int d = abs(nums[i] - nums[j]);
                vec[idx++] = d;
            }
        }

        nth_element(begin(vec), begin(vec)+(k-1), end(vec));

        return vec[k-1];
    }
};

// -------------------------------- Approach - 3 -------------------------------
// Binary Search + Sliding Window

class Solution {
public:
    int slidingWindowCount(vector<int>& nums, int d){
        int i = 0; 
        int j = 1;
        int pairCount = 0;
        int n = nums.size();

        while(j < n){
            while(nums[j] - nums[i] > d){
                i++;
            }

            pairCount += (j-i);
            j++;
        }

        return pairCount;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));

        int l = 0;
        int r = nums[n-1] - nums[0];

        int result = 0; 

        while(l <= r){
            int mid = l + (r-l) / 2;

            int countPair = slidingWindowCount(nums, mid);

            if(countPair < k){
                l = mid + 1;
            } else {
                result = mid;
                r = mid - 1;
            }
        }

        return result;
    }
};