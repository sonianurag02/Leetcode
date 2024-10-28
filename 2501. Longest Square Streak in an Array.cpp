// ------------------------------ Approach - 1 ---------------------------------
// Using Unordered map

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> mp;

        sort(begin(nums), end(nums));

        int maxStreak = 0;

        for(int num: nums){
            int root = (int)sqrt(num);

            if(root * root == num){
                mp[num] = mp[root] + 1;
            } else {
                mp[num] = 1;
            }

            maxStreak = max(maxStreak, mp[num]);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};

// ------------------------------ Approach - 2 ---------------------------------
// Using Unordered set

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));

        int maxStreak = 0;

        for(int &num: nums){
            int streak = 0;

            long long curr = num;

            while(st.find(curr) != st.end()){
                streak++;

                if(curr * curr > 1e5){
                    break;
                }

                curr *= curr;
            }

            maxStreak = max(maxStreak, streak);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};