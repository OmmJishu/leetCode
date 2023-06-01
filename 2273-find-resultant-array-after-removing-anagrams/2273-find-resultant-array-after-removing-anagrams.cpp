class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        vector<string> temp(words.size(),"");
        
        for(int i = 0; i<words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
           
            if(s1 == s2){
                temp[i+1] = words[i+1];
            }
        }
        
        vector<string> res;
        for(int i = 0; i<words.size(); i++){
            if(temp[i] == "")
                res.push_back(words[i]);
        }
        temp.clear();
        
        return res;
    }
};