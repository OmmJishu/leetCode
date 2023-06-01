class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st;
        for(auto it : arr)
            st.insert(it);
        
        vector<int> temp(st.begin(),st.end());
        sort(temp.begin(),temp.end(), greater<int>());
        
        unordered_map<int,int> mp;
        for(int i = 0; i< temp.size(); i++)
            mp[temp[i]] = i;
        
        vector<int> rank(arr.size());
        for(int i = 0; i<arr.size(); i++){
            auto it = mp.find(arr[i]);
            rank[i] = temp.size()-it->second;
        }
        return rank;
    }
};