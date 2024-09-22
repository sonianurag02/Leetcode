// -------------------- Approach - 1 ----------------------
// Brute Force

class Solution {
public:
    int mySqrt(int x) {

        if(x == 0){
            return 0;
        }

        int ans = 1;

        for(long long i = 1; i <= x; i++){
            if(i * i <= x){
                ans = i;
            } else {
                break;
            }
        }

        return ans;
    }
};

// -------------------- Approach - 2 ----------------------
// Binary Search

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;

        int lo = 1, hi = x;
        int ans;

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (mid == x / mid) return mid; // mid*mid==x is=> mid==x/mid;
            else if(mid < x / mid){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid-1;
        }
        
        return ans;
    }
};