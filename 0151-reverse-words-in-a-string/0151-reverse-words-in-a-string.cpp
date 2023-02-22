class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        // vector<string> res;
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
                // res.push_back(st);
                // res.push_back(' ');
                res = res + st + ' ';
            }
        }
        res.erase(res.begin()+res.size()-1);
        return res;
    }
};