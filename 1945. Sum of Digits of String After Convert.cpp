// -------------------------- Approach - 1 --------------------------------------

class Solution {
public:
    int getLucky(string s, int k) {
        int currNum = 0;

        for(char& c: s){
            int number = c - 'a' + 1;
            while(number > 0){
                currNum += number % 10;
                number /= 10;
            }
        }

        while(k > 1){
            int digit = 0;
            while(currNum > 0){
                digit += currNum % 10;
                currNum /= 10;
            }
            currNum = digit;
            cout<<currNum<<" ";
            k--;
        }

        return currNum;
    }
};