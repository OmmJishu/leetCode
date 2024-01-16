class Solution {
public:
    string minWindow(string s, string t) {
    if(s.size()<t.size() || s.empty() || t.empty()) return "";
        
        unordered_map<char,int> mpT;
        for(auto it : t) mpT[it]++;
        
        int mini = INT_MAX;
        int j = 0, cnt = 0;
        unordered_map<char,int> curr;
        int idx = INT_MAX;
        
        for(int i = 0; i<s.size(); i++){
            if(mpT.find(s[i]) != mpT.end()){
                if(++curr[s[i]] <= mpT[s[i]])
                    cnt++;
            }
            
            if(cnt == t.size()){
                while(mpT.find(s[j]) == mpT.end() || curr[s[j]] > mpT[s[j]]){
                    curr[s[j]]--;
                    j++;
                }
               
                if(i - j + 1 < mini){
                    mini = i - j + 1;
                    idx = j;
                }
                
                curr[s[j]]--;
                j++;
                cnt--;
            }
        }
        
        return idx == INT_MAX ? "" : s.substr(idx,mini);
    }
};