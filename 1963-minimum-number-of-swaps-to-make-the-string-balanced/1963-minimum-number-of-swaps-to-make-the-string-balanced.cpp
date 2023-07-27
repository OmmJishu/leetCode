class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '['){
                stk.push('[');
            }
            else if(stk.empty() && s[i] == ']'){
                stk.push(']');
            }
            else if(!stk.empty() && s[i] == ']'){
                if(stk.top() == '[')
                    stk.pop();
                else
                    stk.push(']');
            }
        }
        
        int sz = stk.size()/2;
        
        return (sz%2 == 1) ? (sz + 1)/2 : sz/2;
    }
};