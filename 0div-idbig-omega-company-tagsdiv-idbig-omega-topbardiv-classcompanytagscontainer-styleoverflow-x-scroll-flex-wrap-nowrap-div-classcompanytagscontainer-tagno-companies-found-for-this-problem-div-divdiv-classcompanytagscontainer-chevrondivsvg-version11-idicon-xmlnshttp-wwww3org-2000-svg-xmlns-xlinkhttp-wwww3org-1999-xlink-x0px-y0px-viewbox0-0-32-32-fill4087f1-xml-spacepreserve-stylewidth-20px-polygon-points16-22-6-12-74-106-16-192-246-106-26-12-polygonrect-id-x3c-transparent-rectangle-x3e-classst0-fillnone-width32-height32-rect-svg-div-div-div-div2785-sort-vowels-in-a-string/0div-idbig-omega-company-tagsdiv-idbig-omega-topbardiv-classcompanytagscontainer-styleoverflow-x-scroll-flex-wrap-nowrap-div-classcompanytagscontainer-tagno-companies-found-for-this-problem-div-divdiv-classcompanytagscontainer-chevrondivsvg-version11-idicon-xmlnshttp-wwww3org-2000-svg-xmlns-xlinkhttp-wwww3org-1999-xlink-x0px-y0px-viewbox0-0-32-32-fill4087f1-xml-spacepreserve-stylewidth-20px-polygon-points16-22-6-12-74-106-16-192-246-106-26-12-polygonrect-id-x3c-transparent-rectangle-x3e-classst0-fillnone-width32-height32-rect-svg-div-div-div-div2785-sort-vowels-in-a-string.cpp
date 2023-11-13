class Solution {
public:
    string sortVowels(string s) {
        string vowel = "";
        set<char> st{'a','e','i','o','u','A','E','I','O','U'};
        for(int i = 0; i<s.size(); i++){
            if(st.find(s[i]) != st.end())
                vowel += s[i];
        }
        sort(vowel.begin(),vowel.end());
        
        int j = 0;
        for(int i = 0; i<s.size(); i++){
            if(st.find(s[i]) != st.end())
                s[i] = vowel[j++];
        }
        
        return s;
    }
};