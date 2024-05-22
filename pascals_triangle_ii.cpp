#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r(rowIndex+1, 0);
        r[0] = 1;
        for(int i = 1; i < rowIndex+1; ++i){
            cout<<"i = "<<r[i]<<endl;
            for(int j = i; j >= 1; --j){
                r[j] += r[j-1];
                cout<<"j = "<<r[j]<<endl;
            }
        }
        return r;
    }
};

int main(){
    Solution s1;
    vector<int> r;
    s1.getRow(3);
}