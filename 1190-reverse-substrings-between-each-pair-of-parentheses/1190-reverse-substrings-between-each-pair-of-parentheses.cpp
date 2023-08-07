class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ')'){
                string temp = "";
                while(!stk.empty() && stk.top() != '('){
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop();
                for(auto it : temp)
                    stk.push(it);
            }
            else
                stk.push(s[i]);
        }
        
        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        
        return res;
    }
};