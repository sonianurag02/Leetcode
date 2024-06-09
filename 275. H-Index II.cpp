// ------------------------ Code ---------------------------------------

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n-1;
        int ans = 0;

        while(left <= right){
            int mid = (left+right)/2;
            int idx = n - mid;

            if(citations[mid] >= idx){
                ans = idx;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};