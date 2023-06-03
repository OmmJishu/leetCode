class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> st;
        for(auto it : sentence)
            st.insert(it);
        
        sentence = "";
        for(auto it : st)
            sentence = sentence + it;
        sort(sentence.begin(),sentence.end());
        
        string s = "abcdefghijklmnopqrstuvwxyz";
        if(sentence.size()<s.size()) 
            return false;
        
        for(int i = 0; i<26; i++){
            if(sentence[i] != s[i])
                return false;
        }
        
        return true;
    }
};