// ------------------------ Approach - 1 ------------------------------------
// Brute force

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for(string str: details){
            string age = str.substr(11, 2);
            if(stoi(age) > 60){
                count++;
            }
        }

        return count;
    }
};

// ------------------------ Approach - 2 ------------------------------------

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(int i=0;i<details.size();i++)
        {
            int age=( (details[i][11]-'0')*10 )+(details[i][12]-'0');
            ans+=(age>60);
        }
        return ans;
    }
};