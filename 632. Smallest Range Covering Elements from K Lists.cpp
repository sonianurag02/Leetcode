// ------------------------------- Approach - 1 -----------------------------------------
// Using two pointers

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> a;
        for(int i = 0; i < nums.size(); i++){
            for(int j: nums[i]){
                a.push_back({j, i});
            }
        }

        sort(a.begin(), a.end());

        int mini = 1e9;
        int diff = nums.size();
        int mp[diff];
        int total = 0;
        int j = 0;

        vector<int> ans;

        memset(mp, 0, sizeof(mp));

        for(int i = 0; i < (int)a.size(); i++){
            mp[a[i].second]++;
            if(mp[a[i].second] == 1) total++;
            if(total == diff){
                if(a[i].first - a[j].first + 1 < mini){
                    mini = a[i].first - a[j].first + 1;
                    ans = {a[j].first, a[i].first};
                }
            }
            if(total == diff){
                while(total == diff){
                    if(mp[a[j].second] > 1) {
                        mp[a[j].second]--;
                        j++;
                    } else {
                        break;
                    }
                }
                if(a[i].first - a[j].first + 1 < mini){
                    mini = a[i].first - a[j].first + 1;
                    ans = {a[j].first, a[i].first};
                }
            }
        }

        return ans;
    }
};

// ------------------------------- Approach - 2 -----------------------------------------
// TLE

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        vector<int> vec(k, 0); // {0, 0, 0, ...}

        vector<int> resultRange = {-1000000, 1000000}; // {a, b}

        while(true){
            int minEl = INT_MAX;
            int maxEl = INT_MIN;
            int minElListIdx = 0;

            for(int i = 0; i < k; i++){
                int listIdx = i;
                int elIdx = vec[i];
                int element = nums[listIdx][elIdx];

                if(element < minEl){
                    minEl = element;
                    minElListIdx = listIdx;
                }

                maxEl = max(maxEl, element);
            }

            // range (minEl, maxEl)
            if(maxEl - minEl < resultRange[1] - resultRange[0]){
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            // Now shorten this range by moving minElement Idx
            int nextIndex = vec[minElListIdx] + 1;
            if(nextIndex >= nums[minElListIdx].size()){
                break;
            }
            vec[minElListIdx] = nextIndex;
        }

        return resultRange;
    }
};

// ------------------------------- Approach - 3 -----------------------------------------
// Using min-heap

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        // {Element, listIndex, ElementIndex} -> vector<int> {a, b, c}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int maxEl = INT_MIN;
        for(int i = 0; i < k; i++){
            pq.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        vector<int> resultRange = {-1000000, 1000000};

        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int listIdx = curr[1];
            int idx = curr[2];

            if(maxEl - minEl < resultRange[1] - resultRange[0]){
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            // Decrease the range from minimum side
            if(idx + 1 < nums[listIdx].size()){
                int nextEl = nums[listIdx][idx+1];
                pq.push({nextEl, listIdx, idx + 1});
                maxEl = max(maxEl, nextEl);
            } else {
                break;
            }
        }

        return resultRange;
    }
};