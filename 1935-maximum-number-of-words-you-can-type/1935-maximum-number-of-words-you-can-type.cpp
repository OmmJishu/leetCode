class Solution {
public:
    int canBeTypedWords(string t, string b) {
        t += ' ';
        unordered_set<char> st;
        for(auto it : b) st.insert(it);
        int cnt = 0, n = t.size();
        for(int i = 0; i<n; i++){
            bool find = false;
            while(i<n && t[i] != ' '){
                if(st.find(t[i]) != st.end()) find = true;
                i++;
            }
            if(find == false) cnt++;
        }
        return cnt;
    }
};