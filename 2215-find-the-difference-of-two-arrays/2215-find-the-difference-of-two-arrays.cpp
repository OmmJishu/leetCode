class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        unordered_map<int,int> mp1,mp2;
        for(auto it : nums1)    
            mp1[it]++;
        for(auto it : nums2)    
            mp2[it]++; 
        vector<int> temp;
        for(auto it : mp1){
            if(mp2.find(it.first) == mp2.end())
                temp.push_back(it.first);
        }
        res.push_back(temp);
        temp.clear();
        for(auto it : mp2){
            if(mp1.find(it.first) == mp1.end())
                temp.push_back(it.first);
        }
        res.push_back(temp);
        return res;
    }
};