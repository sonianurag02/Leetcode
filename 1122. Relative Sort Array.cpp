// --------------- Approach - 1 (Brute Force Approach) ---------------------------

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr1.begin(), arr1.end());

        int i = 0;
        for(int j = 0; j < m; j++){
            for(int k = i; k < n; k++){
                if(arr2[j] == arr1[k]){
                    swap(arr1[i], arr1[k]);
                    i++;
                }
            }
        }
        sort(arr1.begin()+i, arr1.end());

        return arr1;
    }
};

// --------------- Approach - 2 (Using Hash Map) ---------------------------

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        vector<int> result, remaining;

        for(int i: arr2){
            mp[i] = 0;
        }

        for(int i: arr1){
            if(mp.find(i) != mp.end()){
                mp[i]++;
            }
            else{
                remaining.push_back(i);
            }
        }

        sort(remaining.begin(), remaining.end());

        for(int i = 0; i < arr2.size(); i++){
            for(int j = 0; j < mp[arr2[i]]; j++){
                result.push_back(arr2[i]);
            }
        }

        for(int i = 0; i < remaining.size(); i++){
            result.push_back(remaining[i]);
        }

        return result;
    }
};

// --------------- Approach - 3 (Using Counting Sort) ---------------------------

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxElement = *max_element(arr1.begin(), arr1.end());
        vector<int> count(maxElement + 1);

        for(int element: arr1){
            count[element]++;
        }

        vector<int> result;

        for(int element: arr2){
            while(count[element] > 0){
                result.push_back(element);
                count[element]--;
            }
        }

        for(int i = 0; i <= maxElement; i++){
            while(count[i] > 0){
                result.push_back(i);
                count[i]--;
            }
        }
        return result;
    }
};