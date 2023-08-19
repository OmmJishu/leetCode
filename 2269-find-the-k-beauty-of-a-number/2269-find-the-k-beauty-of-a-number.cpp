class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string s = to_string(num);
        
        for (int i = 0; i + k <= s.size(); i++) {
            int window = stoi(s.substr(i, k));
            if (window != 0 && num % window == 0)
                ans++;
        }
        
        return ans;
    }
};