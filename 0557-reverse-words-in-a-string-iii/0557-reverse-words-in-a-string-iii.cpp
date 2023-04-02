class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' ')
                continue;
            else{
                string st = "";
                int j;
                for(j = i; j<s.size(); j++){
                    if(s[j] == ' ')
                        break;
                    st = st + s[j];
                }
                i = j;
                reverse(st.begin(),st.end());
                res = res + st + ' ';
            }
        }
        res.erase(res.begin()+res.size()-1);
        return res;
    }
};