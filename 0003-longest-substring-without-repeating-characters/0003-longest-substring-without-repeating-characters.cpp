class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")
            return 0;
        
        int i = 0, j = 0,maxLen = 0,n = s.size();
        unordered_set<char> uniqueChar;
        
        // sliding window 
        while(i<n && j<n){
            if(uniqueChar.find(s[j]) == uniqueChar.end()){
                uniqueChar.insert(s[j]);
                j++;
                maxLen = max(maxLen,j-i);
            }
            else{
                uniqueChar.erase(s[i]);
                i++;
            }
        }
        
        return maxLen;
    }
};