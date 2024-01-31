class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        
        int i = 0, j = 0, n = nums.size();
        int sum = 0, maxi = 0;
        
        while(i<n && j<n){
            if(st.find(nums[j]) == st.end()){
                sum += nums[j];
                maxi = max(maxi,sum);
                st.insert(nums[j]);
                j++;
            }
            else{
                sum -= nums[i];
                // maxi = max(maxi,sum);
                st.erase(nums[i]);
                i++;
            }
        }
        
        return maxi;
    }
};