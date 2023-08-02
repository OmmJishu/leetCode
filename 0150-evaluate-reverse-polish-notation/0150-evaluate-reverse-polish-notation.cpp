class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int num = 0;
        for(int i = 0; i<tokens.size(); i++){
            if(tokens[i] == "+"){
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(a+b);
            }
            else if(tokens[i] == "-"){
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b-a);
            }
            else if(tokens[i] == "*"){
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b*a);
            }
            else if(tokens[i] == "/"){
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b/a);
            }
            else {
                int num = 0;
                for(auto it : tokens[i])
                    if(it != '-')
                        num = num * 10 + (it-'0');
                if(tokens[i][0] == '-')
                    num = -num;
                stk.push(num);
            }
        }
       
        return stk.top();
    }
};