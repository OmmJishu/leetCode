class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size();
        int pref = 1, suff = 1;
        
        for(int i = 0; i<n; i++){
            if(pref == 0)
                pref = 1;
            pref *= nums[i];
            ans = max(ans,pref);
        }
        
        for(int i = n-1; i>=0; i--){
            if(suff == 0)
                suff = 1;
            suff *= nums[i];
            ans = max(ans,suff);
        }
        
        return ans;
    }
};