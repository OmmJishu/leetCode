class Solution {
public:
    int countSubstrings(string s) {
        string res = "";
        int n = s.size(), resLen = 0;
        int cnt = 0;
        
        for(int i = 0; i<n; i++){
            // odd length pallindrom
            int l = i, r = i;
            while(l>=0 && r<n && s[l] == s[r]){
                if(r-l+1 > resLen){
                    res = s.substr(l,r-l+1);
                    resLen = r-l+1;
                }
                cnt++;
                l--;
                r++;
            }
            
            // Even length pallindrom
            l = i; r = i+1;
            while(l>=0 && r<n && s[l] == s[r]){
                if(r-l+1 > resLen){
                    res = s.substr(l,r-l+1);
                    resLen = r-l+1;
                }
                cnt++;
                l--;
                r++;
            }
        }
        
        return cnt;
    }
};