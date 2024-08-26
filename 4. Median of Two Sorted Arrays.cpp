// -------------------------- Approach - 1 --------------------------------
// Brute force 1

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int size = m+n;
        vector<int> vec(size);

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), vec.begin());

        for(int num: vec){
            cout<<num<<" ";
        }
       
        return (size) % 2 == 0 ? (double)((vec[size/2] + vec[size/2 - 1]) / 2.0) : (double)vec[size/2] ;
    }
};

// -------------------------- Approach - 2 --------------------------------
// Brute force 2

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> merged(m + n);
        int i = 0, j = 0, k = 0;

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                merged[k] = nums1[i];
                i++;
            }
            else{
                merged[k] = nums2[j];
                j++;
            }
            k++;
        }
        while(i < m){
            merged[k] = nums1[i];
            i++;
            k++;

        }
        while(j < n){
            merged[k] = nums2[j];
            j++;
            k++;

        }
        if((m + n) % 2 != 0){
            return merged[(m + n) / 2];
        }
        else{
            int x = (m + n) / 2;
            double p = merged[x];
            double q = merged[x - 1];
            return (p + q) / 2;
        }
    }
};

// -------------------------- Approach - 3 --------------------------------
// Better Approach

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int size = m+n;

        int idx1 = (size/2)-1;
        int element1 = -1;

        int idx2 = (size/2);
        int element2 = -1;

        int i = 0, j = 0, k = 0;

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                if(k == idx1){
                    element1 = nums1[i];
                }
                if(k == idx2){
                    element2 = nums1[i];
                }
                i++;
            } else {
                if(k == idx1){
                    element1 = nums2[j];
                }
                if(k == idx2){
                    element2 = nums2[j];
                }
                j++;
            }
            k++;
        }
        while(i < m){
            if(k == idx1){
                element1 = nums1[i];
            }
            if(k == idx2){
                element2 = nums1[i];
            }
            i++;
            k++;
        }
        while(j < n){
            if(k == idx1){
                element1 = nums2[j];
            }
            if(k == idx2){
                element2 = nums2[j];
            }
            j++;
            k++;
        }

        if(size % 2 == 1){
            return element2;
        }
        else{
            return (element1 + element2) / 2.0;
        }
    }
};

// -------------------------- Approach - 4 --------------------------------
// Best Approach (Using Binary Search)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int l = 0;
        int r = m;

        while(l <= r){
            int Px = l + (r - l) / 2; // mid from nums1
            int Py = (m + n + 1) / 2 - Px; // from nums2

            int x1 = (Px == 0) ? INT_MIN : nums1[Px - 1];
            int x2 = (Py == 0) ? INT_MIN : nums2[Py - 1];

            int x3 = (Px == m) ? INT_MAX : nums1[Px];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];
            
            if(x1 <= x4 && x2 <= x3){
                if((m+n) % 2 == 1){
                    return max(x1, x2);
                }

                return (max(x1, x2) + min(x3, x4)) / 2.0;
            } else if(x1 > x4){
                r = Px - 1;
            } else {
                l = Px + 1;
            }
        }

        return -1;
    }
};