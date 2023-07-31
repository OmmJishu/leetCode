class Solution {
public:
    int countCollisions(string s) {
        int count = 0; 
        stack<char> stk;
        
        for(int i = 0; i<s.size(); i++){
            if(stk.empty())
                stk.push(s[i]);
            else{
                char top = stk.top();
                if(top=='S' && s[i]=='L'){ 
                    stk.pop();
                    s[i] = 'S';
                    i--;
                    count++;
                }
                else if(top=='R' && s[i]=='L'){
                    stk.pop();
                    s[i] = 'S';
                    i--;
                    count+=2;
                }
                else if(top=='R' && s[i]=='S'){
                    stk.pop();
                    s[i] = 'S';
                    i--;
                    count++;
                }
                else
                    stk.push(s[i]);
            }
        }
        
        return count;
    }
};