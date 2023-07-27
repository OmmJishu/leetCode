class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        stack<int> stk;
        
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                stk.push(0);
            }
            else{
                if(stk.top() == 0){
                    stk.pop();
                    stk.push(1);
                }
                else{
                    int temp = 0;
                    while(!stk.empty() && stk.top() != 0){
                        temp += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    stk.push(2*temp);
                }
            }
        }
        
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        
        return res;
    }
};