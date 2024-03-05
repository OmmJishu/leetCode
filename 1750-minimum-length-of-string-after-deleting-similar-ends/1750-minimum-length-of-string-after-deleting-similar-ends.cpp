class Solution {
public:
    int minimumLength(string s) {
        if(s.size()==1) return 1;
        
        int n = s.size();
        int i = 0, j = n-1;
        
        while(i < j){
            if(s[i]==s[j]){
                char c = s[i];
                while(i <= j && s[i] == c) i++;
                while(i<=j && s[j] == c) j--;}
            else{
                return j-i+1;
            }
        }
        
        if(i==j) return 1;
        return 0;
    }
};