// ------------------------------ Approach - 1 (Using Shell sort) --------------------

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        for(int gap = n/2; gap > 0; gap/=2){
            for(int i = gap; i < n; i++){
                int temp = nums[i];
                int j;

                for(j = i; j >= gap && nums[j - gap] > temp; j -= gap){
                    nums[j] = nums[j-gap];
                }

                nums[j] = temp;
            }
        }

        return nums;
    }
};

// ------------------------------ Approach - 2 (Using Merge sort) --------------------

class Solution {
public:
    void merge(vector<int>& nums, int mid, int low, int high){
        int i, j, k;
        vector<int> B(high - low + 1);
        i = low;
        j = mid+1;
        k = 0;

        while(i <= mid && j <= high){
            if(nums[i] < nums[j]){
                B[k] = nums[i];
                i++;
                k++;
            }
            else{
                B[k] = nums[j];
                j++;
                k++;
            }
        }
        while(i <= mid){
            B[k] = nums[i];
            i++;
            k++;
        }
        while(j <= high){
            B[k] = nums[j];
            j++;
            k++;
        }
        for(int i = low; i <= high; i++){
            nums[i] = B[i - low];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high){
        if(low < high){
            int mid = (low+high)/2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid+1, high);

            merge(nums, mid, low, high);
        } 
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};