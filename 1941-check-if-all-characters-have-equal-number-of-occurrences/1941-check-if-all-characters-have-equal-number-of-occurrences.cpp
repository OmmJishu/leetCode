class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int hash[26] = {0};
        for(auto it : s)
            hash[it-'a']++;
        for(auto it : hash)
            cout<<it<<" ";
        vector<int> store;
        for(int i = 0; i<26; i++){
            if(hash[i] == 0)
                continue;
            else
                store.push_back(hash[i]);
        }
        for(int i = 0; i<store.size()-1; i++){
            if(store[i] != store[i+1])
                return false;
        }
        return true;
    }
};