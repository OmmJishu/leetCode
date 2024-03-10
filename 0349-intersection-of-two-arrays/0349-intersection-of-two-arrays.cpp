class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int c = 0, d = 0;
        
        // make a set as set do not contain duplicate
        set<int> store;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i]==nums2[j])
                {
                    store.insert(nums1[i]);
                    break;
                }
            }
        }
        
        // set to returntype Vector
        vector<int> result(store.begin(), store.end());
        
        return result;
    }
};