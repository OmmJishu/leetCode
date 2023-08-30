class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_set<int> st;
        for(auto it : ranges)
            for(int i = it[0]; i<=it[it.size()-1]; i++)
                st.insert(i);
        
        for(int i = left; i<=right; i++)
            if(st.find(i) == st.end())
                return false;
        
        return true;
    }
};