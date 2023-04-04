class Solution {
public:
    int secondHighest(string s) {
        set<int> st;
        for(int i = 0; i<s.size(); i++){
            if(isdigit(s[i])){
                int dig = s[i]-'0';
                st.insert(dig);
            }
        }
        vector<int> vec;
        for (auto it : st) {
            vec.push_back(it);
        }
        if(vec.size()<2)
            return -1;
        return vec[vec.size()-2];
    }
};