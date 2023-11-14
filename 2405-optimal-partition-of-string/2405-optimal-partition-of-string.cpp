class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int n = s.size();
        int cnt = 0;
        
        int i = 0, j = 0;
        while(j<n){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
                j++;
            }
            else{
                cnt++;
                st.clear();
                st.insert(s[j]);
                j++;
            }
        }
        cnt++;
        
        return cnt;
    }
};