class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,pair<string,int>>> res;
        
        for(int i = 0; i<sources.size(); i++){
            int sz = sources[i].size();
            
            string s1 = s.substr(indices[i],sz);
            
            if(s1 == sources[i]){
                res.push_back({sz,{targets[i],indices[i]}});
            }
        }
        
        string ans = "";
        
        for(auto it : res)
            cout<<it.first<<" "<<it.second.second<<" "<<it.second.first<<endl;
        
        for(int i = 0; i<s.size(); ){
            
            bool added = false;
            for(auto it : res){
                if(i == it.second.second){
                    ans += it.second.first;
                    added = true;
                    i = i + it.first;
                    break;
                }
            }
            
            if(added == false){
                ans += s[i];
                i++;
            }
            
        }
        
        return ans;
    }
};