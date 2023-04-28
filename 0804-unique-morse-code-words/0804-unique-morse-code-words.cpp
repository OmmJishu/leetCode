class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<char,string> data;
        char ch = 'a';
        for(int i = 0; i<26; i++)
            data[ch++] = code[i];
      
        set<string> st;
        for(int i = 0; i<words.size(); i++){
            string temp = "";
            for(int j = 0; j<words[i].size(); j++){
                temp = temp + data[words[i][j]];
            }
            st.insert(temp);
        }
        return st.size();
    }
};