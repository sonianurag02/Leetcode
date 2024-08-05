// ----------------------------- Approach - 1 -----------------------------------
// Brute Force

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sumSubArray;

        int i = 0;
        int j = 0;
        int sum = 0;
        while(i < n){
            if(j >= n){
                i++;
                j = i-1;
                sum = 0;
            } else{
                sum += nums[j];
                cout<<sum<<" ";
                sumSubArray.push_back(sum);
            }
            j++;
        }

        sort(sumSubArray.begin(), sumSubArray.end());
        
        int result = 0;
        int mod = 1e9 + 7;
        for(int k = left; k <= right; k++){
            result = (result + sumSubArray[k-1]) % mod;
        }

        return result;
    }
};

// ----------------------------- Approach - 2 -----------------------------------
// Using Binary Search and Sliding window


class Solution {
private:
    int mod = 1e9 + 7;
    // Helper function to count subArrays with sum <= target and their total sum
    pair<int, long long> countAndSum(vector<int>& nums, int n, int target){
        int count = 0;
        long long currentSum = 0, totalSum = 0, windowSum = 0;

        for(int j = 0, i = 0; j < n; j++){
            currentSum += nums[j];
            windowSum += nums[j] * (j-i+1);
            while(currentSum > target){
                windowSum -= currentSum;
                currentSum -= nums[i++];
            }

            count += j-i+1;
            totalSum += windowSum;
        }

        return {count, totalSum};
    }

    // Helper function to find the sum of the first k smallest subarray sums.
    long long sumOfFirstK(vector<int>& nums, int n, int k){
        int minSum = *min_element(nums.begin(), nums.end());
        int maxSum = accumulate(nums.begin(), nums.end(), 0);
        int left = minSum, right = maxSum;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(countAndSum(nums, n, mid).first >= k){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        auto [count, sum] = countAndSum(nums, n, left);

        return sum - left * (count - k);
    }
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long result = (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) % mod;
        return (result + mod) % mod;
    }
};

// ----------------------------- Approach - 3 -----------------------------------
// Using Priority Queue

class Solution {
public:
    typedef pair<int, int> P;
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P, vector<P>, greater<P>> pq;

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        int result = 0;

        for(int count = 1; count <= right; count++){
            auto p = pq.top();
            pq.pop();

            int sum = p.first;
            int idx = p.second;

            if(count >= left){
                result = (result + sum)  % mod;
            }

            int new_idx = idx+1;
            P new_pair;
            if(new_idx < n){
                new_pair.first = sum + nums[new_idx];
                new_pair.second = new_idx;
                pq.push(new_pair);
            }
        }

        return result;
    }
};
