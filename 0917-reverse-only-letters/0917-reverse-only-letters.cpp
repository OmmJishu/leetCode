class Solution {
public:
    string reverseOnlyLetters(string s) {
        string reversed = "", ans = "";
        for(int i = s.size()-1; i>=0; i--)
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                reversed += s[i];
        int j = 0;
        for(int i = 0; i<s.size(); i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                ans += reversed[j++];
            else
                ans += s[i];
        }
        return ans;
    }
};