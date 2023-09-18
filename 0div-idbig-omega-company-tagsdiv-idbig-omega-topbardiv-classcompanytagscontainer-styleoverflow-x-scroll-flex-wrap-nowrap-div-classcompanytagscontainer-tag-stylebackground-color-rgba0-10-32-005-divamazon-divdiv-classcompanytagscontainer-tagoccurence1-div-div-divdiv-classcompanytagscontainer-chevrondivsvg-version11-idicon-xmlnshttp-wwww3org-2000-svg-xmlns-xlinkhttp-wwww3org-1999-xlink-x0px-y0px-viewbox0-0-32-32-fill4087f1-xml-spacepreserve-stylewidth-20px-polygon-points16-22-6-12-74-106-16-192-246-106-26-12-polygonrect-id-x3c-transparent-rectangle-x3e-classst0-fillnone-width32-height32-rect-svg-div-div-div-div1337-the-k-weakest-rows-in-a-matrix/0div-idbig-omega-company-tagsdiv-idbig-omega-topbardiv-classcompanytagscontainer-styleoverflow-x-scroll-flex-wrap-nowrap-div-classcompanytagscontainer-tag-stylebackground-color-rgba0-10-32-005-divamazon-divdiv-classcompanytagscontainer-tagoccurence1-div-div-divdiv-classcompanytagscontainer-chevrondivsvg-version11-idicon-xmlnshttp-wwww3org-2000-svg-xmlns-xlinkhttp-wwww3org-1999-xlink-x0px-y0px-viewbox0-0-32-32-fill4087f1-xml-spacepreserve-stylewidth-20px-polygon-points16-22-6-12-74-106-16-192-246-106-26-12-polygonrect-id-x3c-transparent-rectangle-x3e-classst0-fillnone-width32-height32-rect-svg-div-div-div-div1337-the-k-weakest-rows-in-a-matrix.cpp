class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> store;
        int i = 0;
        for(auto it : mat){
            int cnt = 0;
            for(auto num : it){
                if(num == 0)
                    break;
                cnt++;
            }
            store.push_back({cnt,i});
            i++;
        }
        
        sort(store.begin(), store.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if(a.first != b.first)
                return a.first < b.first;
            else
                return a.second < b.second;
        });
        

        vector<int> res;
        for(int i = 0; i<k; i++)
            res.push_back(store[i].second); 
        
        return res;
    }
};