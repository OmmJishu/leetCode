class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
        s1 = s1 + ' ';
        s2 = s2 + ' ';
        
        string temp1 = "";
         for(int i = 0; i<s1.size(); i++){
            if(s1[i] == ' '){
                mp1[temp1]++;
                temp1 = "";
            }
             else{
                 temp1 = temp1 + s1[i];
             }
        }
        string temp2 = "";
         for(int i = 0; i<s2.size(); i++){
            if(s2[i] == ' '){
                mp2[temp2]++;
                temp2 = "";
            }
             else{
                 temp2 = temp2 + s2[i];
             }
        }
        
        vector<string> res;
        for(auto it : mp1){
            if(mp2.find(it.first) == mp2.end() && it.second == 1)
                res.push_back(it.first);
        }
        for(auto it : mp2){
            if(mp1.find(it.first) == mp1.end() && it.second == 1)
                res.push_back(it.first);
        }
        
        return res;
    }
};