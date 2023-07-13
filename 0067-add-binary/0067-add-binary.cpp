class Solution {
public:
    string addBinary(string a, string b) {
        int sz = min(a.size(),b.size());
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int mxSz = max(a.size(),b.size());
        
        string res = "";
        vector<char> querry(mxSz,'0');
        
        // For index i = 0
        if(a[0] == '1' && b[0] == '1'){
            res += '0';
            querry[0] = '1';
        }
        else if(a[0] == '0' && b[0] == '0'){
            res += '0';
        }
        else{
            res += '1';
        }
        
        int i = 1;
        for(i = 1; i<sz; i++){
            int num = (a[i]-'0') + (b[i]-'0') + (querry[i-1]-'0');
            
            if(num == 0){
                res += '0';
            }
            else if(num == 1){
                res += '1';
            }
            else if(num == 2){
                res += '0';
                querry[i] = '1';
            }
            else if(num == 3){
                res += '1';
                querry[i] = '1';
            }
        }
        
        if(a.size() == mxSz){
            while(i < mxSz){
                int num = (a[i]-'0') + (querry[i-1]-'0');

                if(num == 0){
                    res += '0';
                }
                else if(num == 1){
                    res += '1';
                }
                else if(num == 2){
                    res += '0';
                    querry[i] = '1';
                }
                
                i++;
            }
        }
        else{
            while(i < mxSz){
                int num = (b[i]-'0') + (querry[i-1]-'0');
                if(num == 0){
                    res += '0';
                }
                else if(num == 1){
                    res += '1';
                }
                else if(num == 2){
                    res += '0';
                    querry[i] = '1';
                }
                
                i++;
            }
        }
        
        
        if(querry[querry.size()-1] == '1')
            res += '1';
        reverse(res.begin(),res.end());
        
        return res;
    }
};