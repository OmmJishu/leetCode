class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        string a1 = "qwertyuiopQWERTYUIOP";
        string a2 = "asdfghjklASDFGHJKL";
        string a3 = "zxcvbnmZXCVBNM";
        
        for(int i = 0; i<words.size(); i++){
            string s = words[i];
            int count = 0;
            for(int j = 0; j<s.size(); j++){
                for(int k = 0; k<a1.size(); k++){
                    if(s[j] == a1[k])
                        count++;
                }
                if(count == s.size()){
                    res.push_back(s);
                    break;
                }
            }
            int count1 = 0;
            for(int j = 0; j<s.size(); j++){
                for(int k = 0; k<a2.size(); k++){
                    if(s[j] == a2[k])
                        count1++;
                }
                if(count1 == s.size()){
                    res.push_back(s);
                    break;
                }
            }
            
            int count2 = 0;
            for(int j = 0; j<s.size(); j++){
                for(int k = 0; k<a3.size(); k++){
                    if(s[j] == a3[k])
                        count2++;
                }
                if(count2 == s.size()){
                    res.push_back(s);
                    break;
                }
            }
        }
        return res;
    }
};