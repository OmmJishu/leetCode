class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_map<int,int> mp;
        int i = 0, j = 0, n = nums.size();
        int cnt = 0, ans = 0;
        set<vector<int>> st;
        
        while(i<n && j<n){
            if(nums[j] % p == 0){
                mp[nums[j]]++;
                cnt++;
            }
            
            if(cnt > k){
                while(cnt > k){
                    if(mp[nums[i]] > 0){
                        mp[nums[i]]--;
                        if(mp[nums[i]] == 0)
                            mp.erase(nums[i]);
                        cnt--;
                    }
                    i++;
                }
            }
            
            
            for(int m = i; m<=j; m++){
                vector<int> tmp;
                for(int p = j; p>=m; p--)
                    tmp.push_back(nums[p]);
                st.insert(tmp);
            }
            
            // ans += (j-i+1);
            j++;
        }
        
        return st.size();
    }
};