class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        set<int> st1;
        vector<int> res;
        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<=i; j++){
                st1.insert(nums[i]);
            }
            set<int> st;
            for(int k = nums.size()-1; k>i; k--){
                st.insert(nums[k]);
            }
            
            res.push_back(st1.size()-st.size());
        }
        return res;
    }
};