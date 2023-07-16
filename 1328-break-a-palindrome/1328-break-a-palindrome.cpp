class Solution {
public:
    string breakPalindrome(string pallindrom) {
        int sz = pallindrom.size();
        if(sz == 1) 
            return "";
        
        char ch = 'a';
        int count = 0;
        for(int i = 0; i<sz; i++){
            if(ch == pallindrom[i])
                count++;
        }
        if(count == sz){
            pallindrom[sz-1] = 'b';
            return pallindrom;
        }
        
        int n = sz/2;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(pallindrom[i] != 'a'){
                pallindrom[i] = 'a';
                cnt++;
                break;
            }
        }
        
        if(cnt == 0 && sz%2 == 1){
            char ch = 'a';
            bool flag = true;
            
            for(int i = n+1; i<sz; i++){
                if(pallindrom[i] != 'a'){
                    pallindrom[i] = 'a';
                    flag = false;
                }   
            }
            if(flag == true){
                pallindrom[sz-1] = 'b';
                return pallindrom;
            }
        }
        
        return pallindrom;
    }
};