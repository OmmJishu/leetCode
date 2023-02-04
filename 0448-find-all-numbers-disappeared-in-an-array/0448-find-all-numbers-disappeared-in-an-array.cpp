class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int hash[100000] = {0};
        for(auto it : nums)
            hash[it]++;
        
        vector<int> res;
        for(int i = 1; i<=n; i++)
            if(hash[i] == 0)
                res.push_back(i);
        return res;
    }
};