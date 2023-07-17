class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto it : nums)
            mp[it]++;
        
        vector<pair<int,int>> store;
        for(auto it : mp)
            store.push_back({it.second,it.first});
        
        sort(store.begin(),store.end());
        vector<int> res;
        
        int k = 0, m = 1,j, n = store.size();
        
        for(int i = 0; i<n; i++){
            if(i+1 < n && store[i].first == store[i+1].first){
                k = i;
                for(j = i; j<n; j++){
                    if(j+1 < n && store[j].first == store[j+1].first){
                        m++;
                    }
                    else
                        break;
                }
                reverse(store.begin()+k, store.begin()+m+k);
                i = j;
                m = 1;
            }
        }
        
        for(auto it : store){
            while(it.first--)
                res.push_back(it.second);
        }
        return res;
    }
};