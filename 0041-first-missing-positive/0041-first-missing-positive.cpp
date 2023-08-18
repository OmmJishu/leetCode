class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int k=1;
		unordered_map<int,int> mp;
        for(auto it : nums){
            if(it > 0)
                mp[it]++;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < 1)
                continue;
            else if(nums[i] >= 1){
                if(mp.find(k) == mp.end()){
                    return k;
                }
                else
                    k++;
            }
        }
        
        return k;
	}
};