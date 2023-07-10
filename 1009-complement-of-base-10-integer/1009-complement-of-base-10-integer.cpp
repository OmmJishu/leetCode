class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        
        string s = "";
        while(n){
            s += to_string(n%2);
            n /= 2;
        }
        
        cout<<s;
        
        int res = 0, j=0;
        reverse(s.begin(),s.end());
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == '0'){
                res += pow(2,j);
            }
            j++;   
        }
        
        return res;
    }
};