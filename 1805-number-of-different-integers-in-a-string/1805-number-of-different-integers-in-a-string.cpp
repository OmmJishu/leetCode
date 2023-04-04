class Solution {
public:
    int numDifferentIntegers(string word) {
        map<string,int> mp;
        for(int i = 0; i<word.size(); i++){
            if(isdigit(word[i])){
                string s = "";
                while (word[i] == '0')
                    i++;
                while(isdigit(word[i])){
                    s = s + word[i];
                    i++;
                }
                mp[s]++;
            }
        }
        for(auto it : mp)
            cout<<it.first<<"  ";
        return mp.size();
    }
};