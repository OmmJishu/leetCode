class Solution {
public:
    int countPairs(vector<int>& d) {
        unordered_set<int> st;
        for(int i = 0; i<=21; i++)
            st.insert(pow(2,i));
        
        long long total = 0;
        
        for(auto it : st){
            unordered_map<int,int> mp;
            long long count = 0;
            for(int i = 0; i<d.size(); i++){
                if(mp.find(it-d[i]) != mp.end())
                    count += mp[it-d[i]];
                mp[d[i]]++;
            }
            total += count;
        }
        return static_cast<int>(total%1000000007);
    }
};