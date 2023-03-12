class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> mp;
        for(auto it : nums)
            mp[it]++;
        
        vector<int> res;
        int count1 = 0, count2 = 0;
        for(auto it : mp){
            if(it.second%2 == 0)
                count1 = count1 + it.second/2;
            else if((it.second - 1)%2 == 0){
                count1 = count1 + it.second/2;
                count2++;
            }
            else
                count2++;
        }
        res.push_back(count1);
        res.push_back(count2);
        return res;
    }
};