class Solution {
public:
    string maxValue(string n, int x) {
        int sz = n.size();
        int idx = sz;
        
        if(n[0] != '-'){
            for(int i = n.size()-1; i>=0; i--){
                if(n[i]-'0' >= x)
                    continue;
                else
                    idx = i;
            }
            n.insert(idx,1,x+'0');
        }
        else{
            for(int i = n.size()-1; i>=1; i--){
                if(n[i]-'0' <= x)
                    continue;
                else
                    idx = i;
            }
            n.insert(idx,1,x+'0');
        }
        
        return n;
    }
};