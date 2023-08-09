class Solution {
private:
    string vow = "aeiou";
public:
    int maxVowels(string s, int k) {
        int cnt = 0, ans = 0;
        for(int i = 0; i<k; i++){
            if(vow.find(s[i]) != string::npos)
                cnt++;
        }
        ans = max(ans,cnt);
       
        for(int i = 1; i+k<=s.size(); i++){
            if(vow.find(s[i-1]) != string::npos)
                cnt--;
            if(vow.find(s[i+k-1]) != string::npos)
                cnt++;
            ans = max(ans,cnt);
        }
        
        return ans;
    }
};