// --------------------------- Approach - 1 (Recursion) ---------------------------------

class Solution {
public:
    int solve(int n, int k){
        if(n == 1){
            return 0;
        }
        return (solve(n-1, k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        return solve(n, k) + 1;
    }
};

// --------------------------- Approach - 2 (Using Vector) ---------------------------------

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> vec;
        
        for(int i = 1; i <= n; i++){
            vec.push_back(i);
        }

        int i = 0;
        while(n > 1){
            i = (i + (k-1)) % n;
            vec.erase(vec.begin() + i);
            n--;
        }

        return vec[0];
    }
};
