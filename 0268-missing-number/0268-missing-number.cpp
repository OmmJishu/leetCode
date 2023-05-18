class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int> hash;
        for(int i = 0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        
        for(int i = 0; i<=nums.size(); i++)
            if(hash.find(i) == hash.end())
                return i;
        return 0;
    }
};