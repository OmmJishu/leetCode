class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        
        for(int i = 0; i<s.size(); i++){
            unordered_map<char,int> mp;
            mp[s[i]]++;
            for(int j = i+1; j<s.size(); j++){
                mp[s[j]]++;
                int mx = INT_MIN, mini = INT_MAX;
                for(auto it : mp){
                    mx = max(mx,it.second);
                    mini = min(mini,it.second);
                }
                sum += (mx-mini);
            }
        }
        
        return sum;
    }
};