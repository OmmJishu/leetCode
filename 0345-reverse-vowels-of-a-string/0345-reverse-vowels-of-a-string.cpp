class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (isvowel(s[i]) && isvowel(s[j]))
                swap(s[i++], s[j--]);
            
            if (!isvowel(s[i]))
                i++;
            
            if (!isvowel(s[j]))
                j--;
        }
        return s;
    }
    
    bool isvowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
};