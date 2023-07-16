class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k)
            return s;
        
        stack<pair<char,short>> stk;
        for(int i = 0; i<n; i++){
            if(stk.empty() || stk.top().first != s[i])
                stk.push({s[i],1});
            else{
                ++stk.top().second;
            }
            if(stk.top().second==k) 
                stk.pop();
        }
        
        string res = "";
        while(!stk.empty()){
            res += string(stk.top().second, stk.top().first); // creates p.second length of string of char p.first
            stk.pop();
        }
        reverse(res.begin(),res.end());
        
        return res;
    }
};



//  ------------   OR     -----------

//     string removeDuplicates(string s, int k) {
//         vector<pair<char, short>> st;
//         string res = "";
        
//         for (auto ch : s) {
//             if (st.empty() || st.back().first != ch) 
//                 st.push_back({ ch, 0 });
            
//             if (++st.back().second == k) 
//                 st.pop_back();
//         }
        
//         for (auto& p : st) 
//             res += string(p.second, p.first); // creates p.second length of string of char p.first
        
//         return res;
//     }
