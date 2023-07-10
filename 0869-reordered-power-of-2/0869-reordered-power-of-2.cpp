class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        
        int i = 31;
        while(i--){
            int a = pow(2,i);
            string temp = to_string(a);
            sort(temp.begin(),temp.end());
            
            if(temp == s)
                return true;
        }
        
        return false;
    }
};