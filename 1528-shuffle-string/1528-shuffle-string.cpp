class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        vector<char> ch(n);
        for(int i = 0; i < s.length(); i++){
            ch[indices[i]]= s[i];
        }
        
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            ans = ans + ch[i];
        }
        return ans;
    }
};