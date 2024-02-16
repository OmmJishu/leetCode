class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto it : arr)
            mp[it]++;
        
        vector<pair<int,int>> store;
        for(auto it : mp)
            store.push_back({it.second,it.first});
        sort(store.begin(),store.end());
        
        int idx = store.size();
        for(int i = 0; i<store.size(); i++){
            if(k - store[i].first>=0){
                k -= store[i].first;
            }
            else{
                idx = i;
                break;
            }
        }
        
        return store.size() - idx;
    }
};