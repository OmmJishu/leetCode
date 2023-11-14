class Solution {
public:
    int countPalindromicSubsequence(string s) {
        cout<<s.size();
        int leftHash[26] = {0};
        int rightHash[26] = {0};
        
        for(auto it : s){
            rightHash[it-'a']++;
        }
        
        int n = s.size();
        int cnt = 0;
        rightHash[s[0]-'a']--;
        
        unordered_set<string> st;
        for(int i = 1; i < n - 1; i++){
            leftHash[s[i-1]-'a']++;
            
            if(rightHash[s[i]-'a'] >= 0)
                rightHash[s[i]-'a']--;
        
            for(char ch = 'a'; ch <= 'z'; ch++){
                int freqLeft = leftHash[ch-'a'];
                int freqRight = rightHash[ch-'a'];
                
                if (freqLeft > 0 && freqRight > 0) {
                    st.insert(string(1, ch) + s[i] + ch);
                    cnt++;
                }
            }
        }
        
        return st.size();
    }
};