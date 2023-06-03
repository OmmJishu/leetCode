class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> st;
        for(auto it : nums1)
            st.insert(it);
        vector<int> temp(st.begin(),st.end());
        nums1 = temp;
        temp.clear();
        st.clear();
        
        for(auto it : nums2)
            st.insert(it);
        for(auto it : st)
            temp.push_back(it);
        nums2 = temp;
        temp.clear();
        st.clear();
        
        for(auto it : nums3)
            st.insert(it);
        for(auto it : st)
            temp.push_back(it);
        nums3 = temp;
        temp.clear();
        st.clear();
        
        map<int,int> mp;
        for(auto it : nums1)
            mp[it]++;
        for(auto it : nums2)
            mp[it]++;
        for(auto it : nums3)
            mp[it]++;
        
        vector<int> res;
        for(auto it : mp)
            if(it.second>=2)
                res.push_back(it.first);
        
        return res;
    }
};