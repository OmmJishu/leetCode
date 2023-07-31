class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) 
            return {};
        int s_len = s.length();
        int p_len = p.length();
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        for(int i=0;i<p_len;i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(freq_p == window) 
            ans.push_back(0);
        
        for(int i = 1; (i+p_len)<=s_len; i++){
            window[s[i-1]-'a']--;
            window[s[i+p_len-1]-'a']++;
            
            if(freq_p == window) 
                ans.push_back(i);
        }
        return ans;
    }
};