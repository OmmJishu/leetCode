class Solution {
public:
    string truncateSentence(string s, int k) {
        s = s+' ';
        string res = "";
        string temp = "";
        int count = 0;
        for(int i = 0; i<s.size(); i++){
            if(count == k)
                break;
            if(s[i] == ' '){
                count++;
                res = res + temp;
                temp = "";
            }
            temp = temp + s[i];
        }
        // res.erase(res.begin()+res.size()-1,res.end());
        return res;
    }
};