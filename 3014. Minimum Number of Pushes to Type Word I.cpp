// ------------------------------ Approach - 1 ------------------------------------
// Using unordered map (brute force)

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

        int count = 1;
        sum = 0;

        for(auto& it: mp){
            if(count <= 8){
                sum += it.second;
                count++;
                cout<<count<<" ";
            } else if(count <= 16){
                sum += (it.second * 2);
                count++;
                cout<<count<<" ";
            } else if(count <= 24){
                sum += (it.second * 3);
                count++;
                cout<<count<<" ";
            } else{
                sum += (it.second * 4);
                count++;
                cout<<count<<" ";
            }
        }

        return sum;
    }
};

// ------------------------------ Approach - 2 ------------------------------------

class Solution {
public:
    int minimumPushes(string word) {
        int result = 0;

        unordered_map<int, int> mp;

        int assign_key = 2;

        for(char& ch: word){
            if(assign_key > 9){
                assign_key = 2;
            }

            mp[assign_key]++;
            result += mp[assign_key];

            assign_key++;
        }

        return result;
    }
};

// ------------------------------ Approach - 3 ------------------------------------

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