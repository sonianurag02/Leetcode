// ----------------------------- Approach - 1 ---------------------------------------------
// Binary Search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // First Occurence of target
        int n = nums.size(), lo, hi, mid;
        vector<int> res;

        if(n == 0){
            return {-1, -1};
        }

        lo = 0, hi = n-1;
        while(lo < hi){
            mid = lo + (hi - lo)/2;

            if(nums[mid] >= target){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        if(nums[lo] == target){
            res.push_back(lo);
        }
        else{
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }

        // Last Occurence of target

        lo = 0, hi = n-1;
        while(lo < hi){
            mid = lo + (hi - lo + 1)/2;

            if(nums[mid] > target){
                hi = mid-1;
            }
            else{
                lo = mid;
            }
        }
        if(nums[lo] == target){
            res.push_back(lo);
        }
        return res;
    }
};