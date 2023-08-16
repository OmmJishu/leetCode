class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream in(s);
        string word;
        int i = 0;

        unordered_map<char, string> mp;
        unordered_map<string, char> revMp;
        
        for (; i < pattern.size() && in >> word; i++) {
            if (mp.find(pattern[i]) == mp.end()) {
                if (revMp.find(word) == revMp.end()) {
                     mp[pattern[i]] = word; // Word is already mapped to a different character
                        revMp[word] = pattern[i];
                }
            }
        }
        
        istringstream inn(s);
        string currWord;
        i = 0;
        for(i = 0; i<pattern.size() && inn >> currWord; i++)
            if(mp[pattern[i]] != currWord)
                return false;
        
        return i == pattern.size() && inn.eof();
    }
};