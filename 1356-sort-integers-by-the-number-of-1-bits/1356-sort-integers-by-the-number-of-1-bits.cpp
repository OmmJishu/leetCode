class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> store;
        
        for(int i = 0; i<arr.size(); i++){
            int n = arr[i];
            int count1 = 0;
            while (n > 0) {
                if(n % 2 == 1)
                    count1++;
                n = n / 2;
            }
            store.push_back({count1,arr[i]});
        }
        sort(store.begin(),store.end());
        vector<int> res;
        for(auto it : store)
            res.push_back(it.second);
        store.clear();
        
        return res;
    }
};