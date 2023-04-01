class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == ' ')
                continue;
            else{
                for(int j = i; j>=0; j--){
                    if(s[j] == ' ')
                        break;
                    else
                        count++;
                }
                break;
            }
        }
        return count;
    }
};