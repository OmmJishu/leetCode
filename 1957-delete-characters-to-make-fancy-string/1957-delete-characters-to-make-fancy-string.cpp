class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i] == s[i+1]){
                res += s[i];
                while(s[i] == s[i+1]){
                    i++;
                }
            }
            res += s[i];
        }
        return res;
    }
};