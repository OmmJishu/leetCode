class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto it : words){
            mp[it]++;
        }
        
        int cnt = 0;
        bool oddCount = false;
        for(auto it : mp){
            auto mirror = string(rbegin(it.first), rend(it.first));
            if(it.first == mirror){
                cnt += 2*(it.second/2);
                if(it.second%2 == 1){
                    oddCount = true;
                }
            }
            else if(mp.find(mirror) != mp.end()){
                cnt += min(it.second,mp[mirror]);
            }
        }
        
        return 2*cnt + (oddCount ? 2 : 0);
    }
};