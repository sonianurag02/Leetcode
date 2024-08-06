// --------------------------------------- Approach - 1 ------------------------------
// Brute Force

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();

        if(n <= 8){
            return n;
        }

        unordered_map<char, int> mp;

        for(auto& ch: word){
            mp[ch]++;
        }

        int sum = 0;

        if(mp.size() <= 8){
            for(auto& it: mp){
                sum += it.second;
            }

            return sum;
        }

        vector<int> temp;

        for(auto& it: mp){
            temp.push_back(it.second);
        }

        sort(rbegin(temp), rend(temp));

        int count = 1;
        sum = 0;

        for(auto& it: temp){
            if(count <= 8){
                sum += it;
                count++;
            } else if(count <= 16){
                sum += (it * 2);
                count++;
            } else if(count <= 24){
                sum += (it * 3);
                count++;
            } else{
                sum += (it * 4);
                count++;
            }
        }

        return sum;
    }
};

// ------------------------------ Approach - 2 ------------------------------------

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);

        for(char& ch: word){
            mp[ch-'a']++;
        }

        sort(begin(mp), end(mp), greater<int>());

        int result = 0;

        for(int i = 0; i < 26; i++){
            int freq = mp[i];

            int press = i/8 + 1;

            result += press * freq;
        }

        return result;
    }
};