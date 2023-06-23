class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        set<char> st;
        for(auto it : allowed)
            st.insert(it);
        for(auto it : words){
            int c = 0;
            for(auto i : it)
                if(st.find(i) == st.end())
                    c++;
            if(c==0)
                count++;
        }
        return count;
    }
};