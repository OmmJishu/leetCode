class Solution {
public:
    int maxPower(string s) {
        int count = 0, mx = 0;
        int n = s.size();
        
        // If only one character
        if(n == 1)
            return 1;
        
        // If all char are differ
        int c=0;
        for(int i = 0; i<n; i++){
            if(s[i]!=s[i+1])
                c++;
        }
        if(c == n)
            return 1;
        
        // For all other cases
        for(int i = 0; i<n;){
            char ch = s[i];
            if(s[i]!=s[i+1]){
                i++;
            }
            while(s[i] == ch){
                count++;
                i++;
                if(i == n)
                    break;
            }
            mx = max(mx,count);
            count = 0;
        }
        return mx;
    }
};