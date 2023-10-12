class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums)
            mp[it]++;
        
        int x = -1;
        long long f = -1;
        for(auto it : mp){
            f = max(f,static_cast<long long>(it.second));
        }
        for(auto it : mp){
            if(static_cast<long long>(it.second) == f)
                x = it.first;
        }
        
        // cout<<x<<" "<<f<<endl;
        unordered_map<int,int> mp2;
        for(int i = 0; i<nums.size(); i++){
            mp2[nums[i]]++;
            if(mp2.find(x) != mp2.end()){
                long long currf = static_cast<long long>(mp2[x]);
                long long currSz = static_cast<long long>(i)+1;
            
                if(currf*2 > currSz){
                    f -= currf;
                    long long rightSz = static_cast<long long>(nums.size()-i)-1;
                    
                    if(f*2 > rightSz){
                        return i;
                    }
                }
            }
        }
        
        return -1;
    }
};