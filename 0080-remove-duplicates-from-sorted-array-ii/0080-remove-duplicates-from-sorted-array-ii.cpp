class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>2)
                mp[nums[i]] = 2;
        }
        nums.clear();
        int sum = 0;
        for(auto it : mp){
            int a = it.second;
            sum = sum+a;
            while(a--)
                nums.push_back(it.first);
        }
        
        return sum;
    }
};