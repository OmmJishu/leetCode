class Solution {
public:
    int ans = 0;
    int getLucky(string s, int k) {
        string num = "";
        for(int i =  0; i<s.size(); i++){
            string st = to_string(s[i] - 96);
            num = num + st;
        }
        int result = 0;
        for(int i = 0; i<num.size(); i++){
            result = result + (num[i]-48);
        }
        if(k == 1)
            return result;
        
        for(int i = 2; i<=k; i++){
            ans = solve(result);
            result = ans;
        }
        return ans;
    }
    private:
    int solve(int num){
        ostringstream str1;
        str1 << num;
        string st = str1.str();
        
        int result = 0;
        for(int i = 0; i<st.size(); i++){
            result = result + (st[i]-48);
        }
        return result;
    }
};