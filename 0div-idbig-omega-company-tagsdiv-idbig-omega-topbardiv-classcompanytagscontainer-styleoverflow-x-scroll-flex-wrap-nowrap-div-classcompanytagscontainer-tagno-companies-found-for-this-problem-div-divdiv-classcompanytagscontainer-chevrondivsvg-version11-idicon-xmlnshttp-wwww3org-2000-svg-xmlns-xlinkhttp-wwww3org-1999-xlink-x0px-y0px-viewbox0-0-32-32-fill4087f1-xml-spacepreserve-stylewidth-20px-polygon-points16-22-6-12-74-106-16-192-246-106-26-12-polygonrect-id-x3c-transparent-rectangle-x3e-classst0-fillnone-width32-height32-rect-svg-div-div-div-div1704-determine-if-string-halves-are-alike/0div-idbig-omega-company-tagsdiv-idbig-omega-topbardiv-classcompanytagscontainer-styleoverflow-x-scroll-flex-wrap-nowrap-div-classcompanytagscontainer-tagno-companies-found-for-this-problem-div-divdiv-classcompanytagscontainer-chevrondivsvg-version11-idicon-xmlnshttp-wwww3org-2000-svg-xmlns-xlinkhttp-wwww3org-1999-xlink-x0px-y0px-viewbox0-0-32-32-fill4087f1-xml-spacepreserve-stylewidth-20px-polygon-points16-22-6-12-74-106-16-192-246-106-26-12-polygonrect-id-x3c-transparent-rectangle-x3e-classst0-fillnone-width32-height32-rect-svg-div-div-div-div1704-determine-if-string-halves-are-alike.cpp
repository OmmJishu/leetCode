class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        int n = s.size();
        int cnt = 0;
        
        for(int i = 0; i<n/2; i++){
            if(st.count(s[i]) > 0)
                cnt++;
        }
        
        for(int i = n/2; i<n; i++){
            if(st.count(s[i]) > 0)
                cnt--;
        }
        
        return cnt == 0;
    }
};