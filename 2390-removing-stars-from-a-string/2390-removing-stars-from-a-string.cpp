class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '*')
                stk.pop();
            else
                stk.push(s[i]);
        }
        string res = "";
        while(!stk.empty()){
            char c = stk.top();
            res.push_back(c);
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};