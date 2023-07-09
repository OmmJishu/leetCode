class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        
        set<int> st(nums.begin(),nums.end());
        nums.clear();
        nums.insert(nums.end(),st.begin(),st.end());
        
        int ans = 0,count = 1;
        
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
                count++;
            }
            else{
                ans = max(ans,count);
                count = 1;
            }
        }
        
        ans = max(ans,count);
        return ans;
    }
};