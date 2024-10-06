// ---------------------- Approach - 1 -------------------------------
// Using vectors and two pointers

class Solution {
public:
    void swap(string& s1, string& s2){
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.length() < sentence2.length()){
            swap(sentence1, sentence2);
        }

        stringstream ss1(sentence1);
        string word1;
        vector<string> vec1;

        while(ss1>>word1){
            vec1.push_back(word1);
        }

        stringstream ss2(sentence2);
        string word2;
        vector<string> vec2;

        while(ss2>>word2){
            vec2.push_back(word2);
        }

        int i = 0, j = vec1.size() - 1; // s1
        int k = 0, l = vec2.size() - 1; // s2

        while(k < vec2.size() && i < vec1.size() && vec1[i] == vec2[k]){
            k++;
            i++;
        }

        while(l >= k && vec2[l] == vec1[j]){
            l--;
            j--;
        }

        return l < k;
    }
};

// ---------------------- Approach - 2 -------------------------------
// Using deque

class Solution {
public:
    void swap(string& s1, string& s2){
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.length() < sentence2.length()){
            swap(sentence1, sentence2);
        }

        stringstream ss1(sentence1);
        string word1;
        deque<string> deq1;

        while(ss1>>word1){
            deq1.push_back(word1);
        }

        stringstream ss2(sentence2);
        string word2;
        deque<string> deq2;

        while(ss2>>word2){
            deq2.push_back(word2);
        }

        while(!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front()){
            deq1.pop_front();
            deq2.pop_front();
        }

        while(!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back()){
            deq1.pop_back();
            deq2.pop_back();
        }

        return deq2.empty();
    }
};