class Solution {
public:
    string invert(string s){
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        return s;
    }
    
    char findKthBit(int n, int k) {
        string s = "";
        s = s+'0';
        
        for(int i = 2; i<=n; i++){
            string temp = invert(s);
            reverse(temp.begin(),temp.end());
            s = s + '1' + temp;
        }
        return s[k-1];
    }
};