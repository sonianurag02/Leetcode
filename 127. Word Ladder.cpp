// -------------------------- Approach - 1 ---------------------
// Using BFS

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> que;

        que.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());

        st.erase(beginWord);

        while(!que.empty()){
            string word = que.front().first;
            int steps = que.front().second;
            que.pop();

            if(word == endWord){
                return steps;
            }

            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    // If exists in the set
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        que.push({word, steps + 1});
                    }              
                }
                word[i] = original;
            }
        }
        return 0;
    }
};