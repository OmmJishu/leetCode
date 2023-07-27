class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> stk;
        
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                stk.push({'(',i});
            }
            else if(stk.empty() && s[i] == ')'){
                stk.push({')',i});
            }
            else if(!stk.empty() && s[i] == ')'){
                if(stk.top().first == '(')
                    stk.pop();
                else
                    stk.push({')',i});
            }
        }
        
        while(!stk.empty()){
            int idx = stk.top().second;
            s.erase(s.begin()+idx);
            stk.pop();
        }
   
        return s;
    }
};