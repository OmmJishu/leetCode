class Solution {
public:
    int minimumSum(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 2; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int rightSmallest = mp.begin()->first;
        
        int sum = INT_MAX;
        int leftSmallest = nums[0];
        
        for(int i = 1; i<nums.size()-1; i++){
            if(nums[i] <= leftSmallest){
                leftSmallest = min(leftSmallest,nums[i]);
                if(i < nums.size()){
                    mp[nums[i+1]]--;
                    if(mp[nums[i+1]] == 0)
                        mp.erase(nums[i+1]);
                }
                rightSmallest = mp.begin()->first;
            }
            else{
                // cout<<leftSmallest<<" "<<nums[i]<<" "<<rightSmallest<<endl;
                if(nums[i] > rightSmallest){
                    int currSum = leftSmallest + nums[i] + rightSmallest;
                    sum = min(sum,currSum);
                }
                
                if(i < nums.size()){
                    mp[nums[i+1]]--;
                    if(mp[nums[i+1]] == 0)
                        mp.erase(nums[i+1]);
                }
                rightSmallest = mp.begin()->first;
            }
        }
        
        return sum != INT_MAX ? sum : -1;
    }
};