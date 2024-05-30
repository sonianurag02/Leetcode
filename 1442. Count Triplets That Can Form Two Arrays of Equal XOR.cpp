// ------------------ Approach - 1 (Brute Force) ---------------------

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        for(int start = 0; start < n - 1; start++){
            int xorA = 0;
            for(int mid = start + 1; mid < n; mid++){
                xorA ^= arr[mid-1];
                int xorB = 0;
                for(int end = mid; end < n; end++){
                    xorB ^= arr[end];

                    if(xorA == xorB) count++;
                }
            }
        }
        return count;
    }
};

// --------------- Approach - 2 ( Nested Prefix XOR) -------------------------

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXor(begin(arr), end(arr));
        prefixXor.insert(prefixXor.begin(), 0);

        int n = prefixXor.size();

        for(int i = 1; i < n; i++){
            prefixXor[i] ^= prefixXor[i-1];
        }

        int triplets = 0;

        for(int i = 0; i < n; i++){
            for(int k = i+1; k < n; k++){
                if(prefixXor[k] == prefixXor[i]){
                    triplets += k-i-1;
                }
            }
        }

        return triplets;
    }
};