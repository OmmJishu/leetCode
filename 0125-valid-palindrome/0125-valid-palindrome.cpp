class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto it: s){
            if(it >= 'A' && it <= 'Z'){
                it = it+32;
                str.push_back(it);
            }
            else if(it >= 'a' && it <= 'z')
                str.push_back(it);
            else if(isdigit(it))
                str.push_back(it);
        }
        int n = str.size();
        if(n==0)
            return true;
        
        for(int i = 0, j=n-1; i<=n/2; i++,j--){
            if(str[i] == str[j])
                continue;
            else
                return false;
        }
        return true;
    }
};