class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> store;
        int count = 0;
        
        if(nums[0]>0)
                return nums[0];
        else if(nums[n-1]<=0)
            return nums[n-1];
        for(int i = 0; i < n; i++){
            if(abs(nums[i])>=0){
                store.push_back({abs(nums[i]),nums[i]});
            }
        }
        sort(store.begin(), store.end());
        
//         for(auto it : store)
//             cout<<it[0]<<"  "<<it[1]<<endl;
        
        if(store[0][0]==abs(store[0][1]) && store[0][0] == store[1][0] && store[0][1]<0 && store[0][1] == store[1][1] && store[1][0] != store[2][0])
            return store[0][1];
        if(store[0][0]>store[0][1] && store[0][0] == store[1][0])
            return store[0][0];
        if(store[0][0]>store[0][1])
            return store[0][1];
        return store[0][0];
    }
};