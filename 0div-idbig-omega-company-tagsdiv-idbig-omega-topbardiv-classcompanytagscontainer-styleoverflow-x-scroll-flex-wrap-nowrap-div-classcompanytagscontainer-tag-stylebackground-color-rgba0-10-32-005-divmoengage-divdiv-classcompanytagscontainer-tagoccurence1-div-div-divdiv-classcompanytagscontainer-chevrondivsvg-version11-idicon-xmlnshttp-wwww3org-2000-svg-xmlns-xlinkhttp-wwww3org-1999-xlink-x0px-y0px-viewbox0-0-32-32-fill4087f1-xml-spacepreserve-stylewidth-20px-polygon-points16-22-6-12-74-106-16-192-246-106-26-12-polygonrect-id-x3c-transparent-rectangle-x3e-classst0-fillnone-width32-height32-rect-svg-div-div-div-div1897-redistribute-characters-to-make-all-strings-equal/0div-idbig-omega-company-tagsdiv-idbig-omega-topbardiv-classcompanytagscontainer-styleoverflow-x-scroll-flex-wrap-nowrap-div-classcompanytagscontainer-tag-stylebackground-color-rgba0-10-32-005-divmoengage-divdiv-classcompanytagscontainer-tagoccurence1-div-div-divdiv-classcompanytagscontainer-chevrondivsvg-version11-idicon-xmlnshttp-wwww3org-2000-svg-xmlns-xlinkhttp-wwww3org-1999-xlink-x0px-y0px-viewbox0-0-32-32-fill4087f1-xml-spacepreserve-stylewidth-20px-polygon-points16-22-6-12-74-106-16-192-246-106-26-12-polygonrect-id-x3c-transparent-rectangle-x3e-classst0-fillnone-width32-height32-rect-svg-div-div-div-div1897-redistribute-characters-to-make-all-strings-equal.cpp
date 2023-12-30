class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        for(auto it : words)
            for(auto ch : it)
                mp[ch]++;
        
        int n = words.size();
        for(auto it : mp){
            if(it.second%n != 0)
                return false;
        }
        return true;
    }
};