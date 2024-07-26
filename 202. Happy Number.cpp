// -------------------------------- Code -------------------------------------------

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(1){
            int sum = 0;
            while(n != 0){
                int rem = n%10;
                sum += rem*rem;
                n /= 10;
            }
            if(sum == 1){
                return true;
            }

            if(s.find(sum) != s.end()) return false;
            s.insert(sum);

            n = sum;
        }
    }
};