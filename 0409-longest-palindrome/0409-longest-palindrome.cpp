class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for(auto it : s)
            mp[it]++;
        
        int oddfreq = 0;
        for(auto it : mp)
            if(it.second%2 != 0)
                oddfreq++;
        
        if(oddfreq > 1) // we can insert only one char with odd freq on middle 
            return s.size()-oddfreq+1; // +1 to tqake one oddfreq char as longest pallindrom
        
        return s.size();
    }
};