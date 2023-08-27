class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> mp;
        
        for(int i = 0; i < cpdomains.size(); i++){
            string it = cpdomains[i];
            int num = 0, n = it.size();
            
            for(int j = 0; j < n; j++){
                if(isdigit(it[j])){
                    num = num*10 + (it[j] - '0');
                }
                else if(it[j] == ' '){
                    continue;
                }
                else{
                    mp[it.substr(j,n-j)] += num;
                    while(j < n && it[j] != '.')
                        j++;
                }
            }
        }
        
        vector<string> res;
        for(auto it : mp){
            string temp = "";
            temp += to_string(it.second);
            temp += ' ' + it.first;
            res.push_back(temp);
        }
        
        return res;
    }
};