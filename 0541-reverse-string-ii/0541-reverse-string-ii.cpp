class Solution {
public:
    string reverseStr(string s, int k) {
        int temp = 0;
        cout<<s.size();
        for (int i = 0; i < s.size(); i = i+2*k)
            reverse(s.begin()+i, min(s.begin()+i+k,s.end()));
        return s;
    }
};