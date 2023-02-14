class Solution {
public:
    int calculate(string s) {
        s=s+'+';
        int n = s.size();
        stack<int> st;
        long long int num = 0;
        char prevSign = '+';
        
        for(int i = 0; i<n; i++){
            if(s[i] == ' ')
                continue;
            else if(isdigit(s[i])){
                num = 10*num + s[i]-'0';
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                if(prevSign == '+')
                    st.push(num);
                else if(prevSign == '-'){
                    st.push(-1*num);
                }
                else if(prevSign == '*'){
                    int temp = st.top();
                    st.pop();
                    st.push(temp*num);
                }
                else if(prevSign == '/'){
                    int temp = st.top();
                    st.pop();
                    st.push(temp/num);
                }
                num = 0;
                prevSign = s[i];
            }
        }
        
        long long res = 0;
        while(!st.empty()){
            res = res+st.top();
            st.pop();
        }
        return res;
    }
};