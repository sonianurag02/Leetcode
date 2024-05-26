// ------------------------ Approach - 1 ------------------------------

class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0, countL = 0;
        for(char& ch: s){
            if(ch == 'A'){
                countA++;
                countL = 0;
                if(countA > 1){
                    return false;
                }
            }
            else if(ch == 'L'){
                countL++;
                if(countL > 2){
                    return false;
                }
            }
            else{
                countL = 0;
            }
        }
        return true;
    }
};