class Solution {
public:
     bool checkPalindrom(string s){
        int n = s.size();
        for(int i = 0, j=n-1; i<=n/2; i++,j--){
            if(s[i] == s[j])
                continue;
            else
                return false;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i<words.size(); i++){
            if(checkPalindrom(words[i]))
                return words[i];
        }
        return "";
    }
};