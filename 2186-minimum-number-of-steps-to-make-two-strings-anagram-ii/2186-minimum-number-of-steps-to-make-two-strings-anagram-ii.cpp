class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mps, mpt;
        for(auto it : s)
            mps[it]++;
        for(auto it : t)
            mpt[it]++;
        
        int steps = 0;
        for(char ch = 'a'; ch<='z'; ch++){
            steps += (abs(mps[ch] - mpt[ch]));
        }
        
        return steps;
    }
};