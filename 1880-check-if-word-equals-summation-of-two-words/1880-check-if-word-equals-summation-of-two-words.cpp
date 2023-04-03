class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        map<char,int> mp;
        char a1 = 'a';
        for(int i = 0; i<26; i++){
            mp[a1] = i;
            a1++;
        }
        int num1 = 0, num2 = 0, num3 = 0;
        for(int i = 0; i<firstWord.size(); i++){
            char ch = firstWord[i];
            for(auto it : mp){
                if(ch == it.first)
                    num1 = num1*10+it.second;
            }
        }
        for(int i = 0; i<secondWord.size(); i++){
            char ch = secondWord[i];
            for(auto it : mp){
                if(ch == it.first)
                    num2 = num2*10+it.second;
            }
        }
        for(int i = 0; i<targetWord.size(); i++){
            char ch = targetWord[i];
            for(auto it : mp){
                if(ch == it.first)
                    num3 = num3*10+it.second;
            }
        }
        if(num1+num2 == num3)
            return true;
        return false;
    }
};