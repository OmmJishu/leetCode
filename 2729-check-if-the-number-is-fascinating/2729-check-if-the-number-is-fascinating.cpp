class Solution {
public:
    bool isFascinating(int n) {
        string s = "";
        s = s + to_string(n) + to_string(2*n) + to_string(3*n);
        sort(s.begin(),s.end());
        if(s[0] == '0') return false;
        for(int i = 0; i<s.size(); i++)
            if(s[i] != i+'1'){
                return false;
            }
        return true;
    }
};