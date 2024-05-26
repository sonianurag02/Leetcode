#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> original;
        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); it++){
            int ele = *it;
            if(find(original.begin(), original.end(), ele) != original.end()){
                nums.erase(it);
                it--;
            }
            else{
                original.push_back(*it);
            }
        }
        return nums.size();
    }
};

int main(){
    Solution s1;
    vector <int> nums {0,0,1,1,1,2,2,3,3,4};

    s1.removeDuplicates(nums); // Calls your implementation
}
