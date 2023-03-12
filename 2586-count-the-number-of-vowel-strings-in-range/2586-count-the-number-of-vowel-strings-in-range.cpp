class Solution {
public:
    int vowelStrings(vector<string>& word, int left, int right) {
        int count = 0;
        for(int i = left; i<=right; i++){
            int len = word[i].size();
            if((word[i][0] == 'a' || word[i][0] == 'e' || word[i][0] == 'i' || word[i][0] == 'o' || word[i][0] == 'u') && 
              (word[i][len-1] == 'a' || word[i][len-1] == 'e' || word[i][len-1] == 'i' || word[i][len-1] == 'o' || word[i][len-1] == 'u')){
                count++;
            }
        }
        return count;
    }
};