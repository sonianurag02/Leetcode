// ------------------------------- Approach - 1 ----------------------------------

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;

        unordered_map<string,int> um;
        string tmp="";
        for(auto& val : s){ 
            if(val == ' '){
                um[tmp]++;
                tmp = "";
            }
            else{
                tmp += val; 
            }
        }
    
        if(tmp != ""){
            um[tmp]++;
            tmp = "";
        }

        vector<string> ans;
        for(auto& val:um){ 
            if(val.second==1){
                ans.emplace_back(val.first);        
            }
        }

        return ans;
    }
};

// ------------------------------- Approach - 2 ----------------------------------
// Using Stringstream

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        stringstream str(s);

        unordered_map<string,int> mp;
        string tmp;
        while(str>>tmp){
            mp[tmp]++;
        }

        vector<string> ans;
        for(auto& val:mp){ 
            if(val.second==1){
                ans.emplace_back(val.first);        
            }
        }

        return ans;
    }
};