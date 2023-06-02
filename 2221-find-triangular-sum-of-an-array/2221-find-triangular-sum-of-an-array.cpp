class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        vector<int> store;
        for(int i = 0; i<nums.size()-1; i++)
            store.push_back(nums[i]+nums[i+1]);
        
        int sz = store.size();
        while(sz>1){
            nums = store;
            store.clear();
            for(int i = 0; i<nums.size()-1; i++){
                store.push_back((nums[i]+nums[i+1])%10);
            }
            sz--;
        }
        

        return store[0]%10;
    }
};