// ----------------------------- Code --------------------------------

class Solution {
public:
    int getNumOfBouquets(vector<int>& bloomDay, int mid, int k){
        int bouquets = 0;
        int consecutiveDays = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                consecutiveDays++;
            }
            else{
                consecutiveDays = 0;
            }

            if(consecutiveDays == k){
                bouquets++;
                consecutiveDays = 0;
            }
        }

        return bouquets;;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int start = 0;
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        int minDays = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(getNumOfBouquets(bloomDay, mid, k) >= m){
                minDays = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        
        return minDays;
    }
};