// --------------------------------------- Approach - 1 -----------------------------------------------

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> L2R(n, 1);
        vector<int> R2L(n, 1);

        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                L2R[i] = max(L2R[i], L2R[i-1]+1);
            }
        }

        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                R2L[i] = max(R2L[i], R2L[i+1]+1);
            }
        }

        int result = 0;
        for(int i = 0; i < n; i++){
            result += max(L2R[i], R2L[i]);
        }
        
        return result;
    }
};

// --------------------Approach - 2 (A bit if change in it) ---------------------------

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> count(n, 1);

        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                count[i] = max(count[i], count[i-1]+1);
            }
        }

        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                count[i] = max(count[i], count[i+1]+1);
            }
        }

        int result = 0;
        for(int i = 0; i < n; i++){
            result += count[i];
        }
        
        return result;
    }
};

// ------------------- Approach - 3 (With O(1) extra space) -------------------------------------------

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int candy = n;
        int i = 1;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            // Increasing slope
            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n){
                    return candy;
                }
            }

            // Decreasing Slope
            int dip = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                dip++;
                candy += dip;
                i++;
            }

            candy -= min(peak, dip);
        }

        return candy;
    }
};