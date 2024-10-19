// ------------------------ Approach - 1 -----------------------
// Brute Force + TLE

class Solution {
public:
    int solve(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }

        int one_step = solve(n - 1);
        int two_steps = solve(n - 2);

        return one_step + two_steps;
    }

    int climbStairs(int n) {
        return solve(n);
    }
};

// ------------------------ Approach - 2 -----------------------
// Recursion + Memoization

class Solution {
public:
    int t[46];
    int solve(int n){
        if(n < 0){
            return 0;
        }

        if(t[n] != -1){
            return t[n];
        }
        
        if(n == 0){
            return 1; // We've got one way to cover all steps
        }

        int one_step = solve(n - 1);
        int two_steps = solve(n - 2);

        return t[n] = one_step + two_steps;
    }

    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};


// ------------------------ Approach - 3 -----------------------
// Bottom-up Approach

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2 || n == 3){
            return n;
        }

        vector<int> arr(n+1);

        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for(int i = 3; i <= n; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }

        return arr[n];
    }
};

// ------------------------ Approach - 4 -----------------------

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2){
            return n;
        }

        int a = 1;
        int b = 2;
        int c = 3;

        for(int i = 3; i <= n; i++){
            c = a + b;

            int temp_b = c;
            a = b;
            b = temp_b;
        }

        return c;
    }
};