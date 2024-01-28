using ll = long long;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<ll,int> mp;
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i<nums.size(); i++)
            mp[static_cast<ll>(nums[i])]++;
        
        int maxi = 0;
        for(auto &[k,m] : mp){
            int it = k;
            if(it != 1){
                int cnt = 0;
                ll itt = static_cast<ll>(it);
                
                if(mp[itt] > 0){
                    while(itt < INT_MAX && mp[itt] > 0){
                        cnt += 2;
                        if(mp[itt] == 1) 
                            break; 
                        mp[itt] = 0;         
                        itt *= itt;
                    }
                    
                    maxi = max(maxi,(cnt%2 == 1 ? cnt : cnt-1));
                }
            }
        }
        
        maxi = max(maxi,(mp[1]%2 == 1 ? mp[1] : mp[1]-1));
        return maxi;
    }
};