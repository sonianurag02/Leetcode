// --------------------- Approach - 1 (Brute Force) TLE ------------------------

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a * a <= c; a++){
            for(long b = 0; b * b <= c; b++){
                if(a * a + b * b == c){
                    return true;
                }
            }
        }
        return false;
    }
};

// ------------------- Approach - 2 (Better Brute Force) TLE ------------------------

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a * a <= c; a++){
            long b = c - (a * a);
            long i = 1, sum = 0;

            while(sum < b){
                sum += i;
                i += 2; 
            }
            if(sum == b){
                return true;
            }
        }
        return false;
    }
};

// -------------------- Approach - 3 (Using sqrt function) ------------------------

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a * a <= c; a++){
            double b = sqrt(c - a * a);
            if(b == (int)b){
                return true;
            }
        }
        return false;
    }
};

// -------------------- Approach - 4 (Using binary search) ------------------------

class Solution {
public:
    bool binarySearch(long long s, long long e, int n){
        if(s > e) return false;

        long long mid = s + (e-s) / 2;

        if(mid * mid == n){
            return true;
        }
        if(mid * mid > n){
            return binarySearch(s, mid-1, n);
        }
        return binarySearch(mid+1, e, n);
    }

    bool judgeSquareSum(int c) {
        for(long long a = 0; a * a <= c; a++){
            int b = c - (int)(a*a);
            if(binarySearch(0, b, b)){
                return true;
            }
        }
        return false;
    }
};