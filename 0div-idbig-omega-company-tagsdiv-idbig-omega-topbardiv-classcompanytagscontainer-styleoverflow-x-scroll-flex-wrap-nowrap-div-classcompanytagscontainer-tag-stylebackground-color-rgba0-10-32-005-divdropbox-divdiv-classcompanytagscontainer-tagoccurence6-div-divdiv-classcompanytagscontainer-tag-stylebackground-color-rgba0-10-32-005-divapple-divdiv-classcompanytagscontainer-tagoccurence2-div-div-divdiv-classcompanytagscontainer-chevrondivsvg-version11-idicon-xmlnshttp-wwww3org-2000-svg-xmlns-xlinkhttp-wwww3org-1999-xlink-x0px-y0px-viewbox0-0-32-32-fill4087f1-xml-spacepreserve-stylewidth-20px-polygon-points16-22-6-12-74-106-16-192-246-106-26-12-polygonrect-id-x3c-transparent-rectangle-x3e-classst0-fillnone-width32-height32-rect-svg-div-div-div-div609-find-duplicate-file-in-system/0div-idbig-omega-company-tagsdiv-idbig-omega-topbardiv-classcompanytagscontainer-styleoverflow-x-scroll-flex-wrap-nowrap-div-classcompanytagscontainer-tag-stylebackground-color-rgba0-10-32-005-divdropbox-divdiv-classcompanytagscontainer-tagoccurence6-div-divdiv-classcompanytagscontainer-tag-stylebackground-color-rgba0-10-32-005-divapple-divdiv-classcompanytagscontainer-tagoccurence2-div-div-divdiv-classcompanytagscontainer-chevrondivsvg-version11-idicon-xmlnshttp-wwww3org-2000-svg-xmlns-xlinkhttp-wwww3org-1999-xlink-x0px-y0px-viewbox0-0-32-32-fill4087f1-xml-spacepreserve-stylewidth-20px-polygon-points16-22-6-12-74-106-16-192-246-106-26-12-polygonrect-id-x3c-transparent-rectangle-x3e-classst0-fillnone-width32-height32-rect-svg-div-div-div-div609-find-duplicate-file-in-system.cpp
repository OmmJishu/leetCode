class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,pair<vector<string>,int>> mp;
        
        for(auto it : paths){
            string directory = "";
            int i;
            for(i = 0; i<it.size(); i++){
                if(it[i] == ' '){
                    directory += '/';
                    break;
                }
                else{
                    directory += it[i];
                }
            }
            
            string file = "";
            string word = "";
            for(i; i<it.size(); i++){
                if(it[i] == ' '){
                    continue;
                }
                else if(it[i] == '('){
                    i++;
                    for(i; i<it.size(); i++){
                        if(it[i] == ')'){
                            break;
                        }
                        word += it[i];
                    }
                    
                    mp[word].first.push_back(directory + file);
                    mp[word].second++;
                    file = "";
                    word = "";
                }
                else{
                    file += it[i];
                }
            }
        }
        
        vector<vector<string>> res;
        for(auto it : mp){
            if(it.second.second > 1)
                res.push_back(it.second.first);
        }
        
        return res;
    }
};