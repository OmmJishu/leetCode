class Solution {
public:
    bool checkZeroOnes(string s) {
        int cnt1 = 0;
        int c = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '1')
                c++;
            else{
                cnt1 = max(cnt1,c);
                c = 0;
            }
        }
        cnt1 = max(cnt1,c);
        
        int cnt0 = 0;
        c = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '0')
                c++;
            else{
                cnt0 = max(cnt0,c);
                c = 0;
            }
        }
        cnt0 = max(cnt0,c);
        
        if(cnt1 > cnt0)
            return true;
        
        return false;
    }
};