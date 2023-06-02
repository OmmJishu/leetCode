class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        string temp = "";
        for(int i = 0; i<s.size(); i++){
            temp = temp + s[i];
            for(int j = 0; j<words.size(); j++)
                if(words[j] == temp)
                    count++;
        }
        return count;
    }
};