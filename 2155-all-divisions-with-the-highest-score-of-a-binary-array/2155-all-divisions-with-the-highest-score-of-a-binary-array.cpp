class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<pair<int,int>> store;
        int n = nums.size();
        
        vector<int> pref(n,0);
        pref[0] = nums[0];
        for(int i = 1; i<n; i++)
            pref[i] = pref[i-1] + nums[i];
        
        
        int countZero = 0;
        store.push_back({pref[n-1],0});
        
        for(int i = 0; i<n; i++){
            if(nums[i] == 0)
                countZero++;
            store.push_back({countZero+(pref[n-1]-pref[i]),i+1});
        }
        
        int maxi = INT_MIN;
        for(auto it : store)
            maxi = max(maxi,it.first);
        
        vector<int> res;
        for(auto it : store)
            if(it.first == maxi)
                res.push_back(it.second);
        
        return res;
    }
};