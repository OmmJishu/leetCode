class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        
        int li = 0, ri = 0;
        int mx = INT_MIN;
        
        for(; li<fruits.size() && ri<fruits.size(); ri++){
            mp[fruits[ri]]++;
            if(mp.size() > 2){
                mx = max(mx,ri-li);
                mp[fruits[li]]--;
                if(mp[fruits[li]] == 0)
                    mp.erase(fruits[li]);
                li++;
            }
        }
        
        mx = max(mx,ri-li);
        return mx;
    }
};