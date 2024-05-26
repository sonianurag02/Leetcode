#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            // for(int j = 0; j<n; j++){
            for(int j = i+1; j<n; j++){ // slightly optimized
                if(i == j){
                    continue;
                }
                else{
                    if((nums[i]+nums[j]) == target){
                        cout<<i<<","<<j<<endl;
                    }
                }
            }
        }
    }
};

int main(){
    vector <int> nums {3,2,4};
    Solution s1;
    s1.twoSum(nums, 6);
}
