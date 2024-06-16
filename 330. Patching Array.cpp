// ------------------------------- Code ---------------------------------

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0;
        int i = 0;
        long long reach = 0;

        while(reach < n){
            if(i >= nums.size()){
                cout<<"Element to be patched: "<<(reach+1)<<endl;
                reach += reach+1;;
                count++;
            }
            else if(i < nums.size() && nums[i] <= (reach + 1)){
                reach += nums[i];
                i++;
            }
            else{
                cout<<"Element missing, hence patching: "<<(reach+1)<<endl;
                reach += reach + 1;
                count++;
            }
        }
        return count;
    }
};