class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(auto it : arr)
           mp[it]++;
        
        int res = -1;
        for(auto it : mp)
            if(it.first == it.second)
                res = max(res,it.first);
        return res;
    }
};