class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        map<int,int> mp;
        for(int i = 0; i<nums.size(); i++)
            mp[nums[i]]++;
        
        while(mp.size()){
            vector<int> temp;
            for(auto it : mp)
                temp.push_back(it.first);
            
            for(auto it : temp)
                if(--mp[it] == 0){
                    mp.erase(it);
                }
            
            res.push_back(temp);
        }
        
        return res;
    }
};