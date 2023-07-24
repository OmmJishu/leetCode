class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if(intervals.size()==1 && intervals[0][0] < intervals[0][1])
            return {-1};
        
        vector<int> nums;
        for(auto it : intervals)
            nums.push_back(it[0]);
        
        int i = 0;
        unordered_map<int,int> mp;
        for(auto it : nums)
            mp[it] = i++;
        
        sort(nums.begin(),nums.end());
        
        
        vector<int> temp;
        for(auto it : intervals)
            temp.push_back(it[1]);
        
        int n = temp.size();
        vector<int> res(n,-1);
        
        for(int i = 0; i<n; i++){
            int idx = lower_bound(nums.begin(),nums.end(),temp[i]) - nums.begin();
            if(idx < n){
                res[i] = mp[nums[idx]];
            }   
        }
        
        return res;
    }
};