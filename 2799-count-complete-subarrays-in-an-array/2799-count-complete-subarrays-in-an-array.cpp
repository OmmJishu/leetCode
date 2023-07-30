class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int k = st.size();
        int count = 0;
        
        set<int> temp;
        int j = 0, n = nums.size();
        
        for(int i = 0; i<n; i++){
            temp.insert(nums[i]);
            if(temp.size()==k){
                count += (n-i);
                temp.clear();
                i = j++;
            }
        }
        
        return count;
    }
};