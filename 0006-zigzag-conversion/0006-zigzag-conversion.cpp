class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string> v(numRows,"");
        int i = 0, j = 0;
        
        while(i<s.size()){
            if(j == numRows-1){
                while(j >= 1 && s[i] != '\0'){
                    v[j--] += s[i++];
                }
            }
            else if(j == 0){
                while(j < numRows-1 && s[i] != '\0'){
                    v[j++] += s[i++];
                }
            }
        }
        
        string res = "";
        for(auto it : v) res += it;
        return res;
    }
};