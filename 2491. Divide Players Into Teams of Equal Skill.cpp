// ---------------------------- Approach - 1 --------------------------------------

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(skill.begin(), skill.end());

        int i = 0;
        int j = n-1;
        int s = skill[i] + skill[j];

        long long chem = 0;
        
        while(i < j){
            int currSum = skill[i] + skill[j];

            if(currSum != s){
                return -1;
            }

            chem += (long long)skill[i] * (long long)skill[j];
            i++;
            j--;
        }

        return chem;
    }
};

// ---------------------------- Approach - 2 --------------------------------------

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        vector<int> vec(1001, 0);
        int sum = 0;

        for(int& s: skill){
            sum += s;
            vec[s]++;
        }

        int teams = n/2;

        if(sum % teams != 0){
            return -1;
        }

        int target = sum / teams;
        long long chem = 0;

        for(int i = 0; i < n; i++){
            int currSkill = skill[i];
            int remainingSkill = target - currSkill;

            if(vec[remainingSkill] <= 0){
                return -1;
            }

            chem += (long long)currSkill * (long long)remainingSkill;
            vec[remainingSkill]--;
        }

        return chem/2;
    }
};