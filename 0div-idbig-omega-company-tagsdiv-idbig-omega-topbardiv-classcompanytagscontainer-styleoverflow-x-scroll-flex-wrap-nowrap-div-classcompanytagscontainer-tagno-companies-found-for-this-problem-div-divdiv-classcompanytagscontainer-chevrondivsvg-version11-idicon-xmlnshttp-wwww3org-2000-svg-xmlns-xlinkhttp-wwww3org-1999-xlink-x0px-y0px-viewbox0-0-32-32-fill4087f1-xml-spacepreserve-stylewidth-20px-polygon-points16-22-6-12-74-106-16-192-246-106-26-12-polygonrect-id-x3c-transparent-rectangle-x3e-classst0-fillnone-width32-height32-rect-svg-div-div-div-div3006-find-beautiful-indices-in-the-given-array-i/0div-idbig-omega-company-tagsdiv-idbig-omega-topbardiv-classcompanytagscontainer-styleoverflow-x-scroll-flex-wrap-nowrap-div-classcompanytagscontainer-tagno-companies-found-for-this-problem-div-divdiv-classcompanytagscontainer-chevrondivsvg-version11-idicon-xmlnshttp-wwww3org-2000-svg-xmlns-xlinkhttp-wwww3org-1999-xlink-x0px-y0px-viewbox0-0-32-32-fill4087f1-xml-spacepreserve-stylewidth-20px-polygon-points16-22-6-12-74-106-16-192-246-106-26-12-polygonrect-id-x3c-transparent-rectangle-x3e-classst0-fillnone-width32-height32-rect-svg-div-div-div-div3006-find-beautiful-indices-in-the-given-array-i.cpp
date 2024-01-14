class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();
        int lena = a.size();
        int lenb = b.size();
        vector<int> res;
        
        vector<string> strA;
        for (int i = 0; i <= n - lena; i++){
            strA.push_back(s.substr(i, lena));
        }
        
        unordered_map<string,vector<int>> mp;
        for (int j = 0; j <= n-lenb; j++) {
            string B = s.substr(j, lenb);
            mp[B].push_back(j);
        }
        
        for (int i = 0; i <= n - lena; i++) {
            string A = strA[i];

            if (A == a) {
                if(!mp[b].empty()){
                    auto it = lower_bound(mp[b].begin(), mp[b].end(), i - k);
                    if (it != mp[b].end() && abs(*it - i) <= k) {
                        res.push_back(i);
                    }
                }
            }
        }

        return res;
    }
};