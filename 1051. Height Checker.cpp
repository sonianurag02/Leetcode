// -------------------- Approach - 1 (Brute Force) -----------------------------------

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        int count = 0;

        vector<int> expected(begin(heights), end(heights));
        sort(begin(expected), end(expected));

        for(int i = 0; i < n; i++){
            if(heights[i] != expected[i]){
                count++;
            }
        }
        return count;
    }
};

// -------------------- Approach - 2 (Bubble Sort) -----------------------------------

class Solution {
    void bubbleSort(vector<int>& arr){
        int n = arr.size();

        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        bubbleSort(sortedHeights);

        int count = 0;

        for(int i = 0; i < sortedHeights.size(); i++){
            if(heights[i] != sortedHeights[i]){
                count++;
            }
        }

        return count;
    }
};

