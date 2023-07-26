class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        long long int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(i-nums[i])==m.end())
            {
                ans+=i;
                m[i-nums[i]]++;
            }
            else
            {
                ans=ans+i-m[i-nums[i]];
                m[i-nums[i]]++;
            }
        }
        return ans;
    }
};