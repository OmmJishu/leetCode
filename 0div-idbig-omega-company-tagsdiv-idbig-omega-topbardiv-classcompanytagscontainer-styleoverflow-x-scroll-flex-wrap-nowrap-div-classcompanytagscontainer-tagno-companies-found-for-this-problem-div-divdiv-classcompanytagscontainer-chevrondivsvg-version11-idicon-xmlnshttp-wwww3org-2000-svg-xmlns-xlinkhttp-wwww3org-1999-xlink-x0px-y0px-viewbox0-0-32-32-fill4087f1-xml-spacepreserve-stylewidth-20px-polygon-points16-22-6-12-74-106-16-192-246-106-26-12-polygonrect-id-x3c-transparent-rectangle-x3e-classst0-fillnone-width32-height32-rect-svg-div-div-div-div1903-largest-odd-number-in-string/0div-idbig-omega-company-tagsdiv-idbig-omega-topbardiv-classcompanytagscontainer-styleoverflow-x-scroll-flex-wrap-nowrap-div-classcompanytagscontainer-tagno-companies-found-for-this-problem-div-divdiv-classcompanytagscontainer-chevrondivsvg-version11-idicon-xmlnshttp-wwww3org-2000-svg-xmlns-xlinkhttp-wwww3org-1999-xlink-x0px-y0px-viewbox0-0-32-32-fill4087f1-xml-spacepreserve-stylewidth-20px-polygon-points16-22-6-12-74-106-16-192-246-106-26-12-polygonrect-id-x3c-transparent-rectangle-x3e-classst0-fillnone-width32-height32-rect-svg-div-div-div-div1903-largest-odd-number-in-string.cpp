class Solution {
public:
    string largestOddNumber(string num) {
        int k = 0;
        for(int i = num.size()-1; i>=0; --i){
            int c = num[i]-'0';
            if(c%2 == 1){
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};