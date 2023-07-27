class Solution {
public:
    int minInsertions(string s) {
        stack<char> stk;
        int res = 0;
        
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(')
                stk.push(s[i]);
            else if(s[i] == ')' && i<s.size() && s[i+1] == ')'){
                if(!stk.empty())
                    stk.pop();
                else
                    res++; // we need one '(' as we found two '))' but not '(' in stack
                i++;
            }
            else if(s[i] == ')' && i<s.size() && s[i+1] != ')'){
                if(!stk.empty()){
                    stk.pop();
                    res++; // we need only one ')'
                }
                else{ // if stack is empty mean we get only one ')' and need one ')' and one '('
                    res += 2;
                }
            }
        }
        
        if(stk.empty())
            return res;
       
        return stk.size()*2 + res;
    }
};