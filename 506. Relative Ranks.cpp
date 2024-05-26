#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> ans = score;
        sort(score.begin(), score.end(), greater<int>());
        vector<string> res(score.size());
        for (int i = 0; i < score.size(); i++){
            if(i == 0){
                res.push_back("Gold Medal");
            }
            else if(i == 1){
                res.push_back("Silver Medal");
            }
            else if(i == 2){
                res.push_back("Bronze Medal");
            }
            else{
                res.push_back(to_string(i+1));
            }
        }
        vector<string> beta(ans.size());
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < score.size() ; j++){
                if(ans[i] == score[j]){
                    beta.push_back(res[j]);
                    break;
                }
            }
        }
        return beta;
    }
};

int main(){
    vector<int> v = {10,3,8,9,4};
    Solution s;
    vector<string> v1 =  s.findRelativeRanks(v);
    for(int i = 0; i < v1.size(); i++){
        cout<< v1[i] <<" ";
    }
}
