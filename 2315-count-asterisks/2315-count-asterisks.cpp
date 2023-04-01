class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '|'){
                for(int j = i+1; j<s.size(); j++){
                    if(s[j] == '|'){
                        i = j;
                        break;
                    }
                }
            }
            else if(s[i] == '*')
                count++;
        }
        return count;
    }
};