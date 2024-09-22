// ----------------------- Approach - 1 --------------------------
// Brute Force

class Solution {
private:
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if((i == 0 || nums[i] > nums[i-1]) && (i == nums.size()-1 || nums[i] > nums[i+1])){
                return i;
            }
        }
        return 0;
    }
};

// ----------------------- Approach - 2 --------------------------
// Binary Search

class Solution {
private:
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 1;
        int high = n-2;
        
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            else if(nums[mid] > nums[mid-1]) low = mid + 1;

            else if(nums[mid] < nums[mid-1]) high = mid - 1;

            else low = mid + 1;
        }

        return -1;
    }
};