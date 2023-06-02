class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        
        for(int i = 0; i<words.size(); i++){
            string temp = "";
            if(words[i].size()>=pref.size())
                for(int j = 0; j<pref.size(); j++){
                    temp =temp + words[i][j];
                }
            if(temp == pref)
                count++;
        }
        return count;
    }
};