class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i<s.size(); i++)
            mp[s[i]] = i;
        
        vector<int> res;
        int maxi = 0, prev = 0;
        
        for(int i = 0; i<s.size(); i++){
            maxi = max(maxi,mp[s[i]]);
            if(i == maxi){
                res.push_back(maxi-prev+1);
                prev = i+1;
            }
        }
        
        return res;
    }
};