class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> mp,mp2;
        for(int i = 0; i<list1.size(); i++)
            mp[list1[i]] = i;
        
        int mini = INT_MAX;
        for(int i = 0; i<list2.size(); i++){
            if(mp.find(list2[i]) != mp.end()){
                mp[list2[i]] = mp[list2[i]] + i;
                mp2[list2[i]] = mp[list2[i]];
                mini = min(mini,mp2[list2[i]]);
            }
        }
        
        vector<string> res;
        for(auto it : mp2)
            if(it.second == mini)
                res.push_back(it.first);
        return res;
    }
};