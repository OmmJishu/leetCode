class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> count;
        int n = rocks.size();
        for (int i = 0; i < n; ++i) 
            count.push_back(capacity[i] - rocks[i]);
        
        sort(count.begin(),count.end());
        
        int i = 0, k = additionalRocks;
        for(i = 0; i<count.size() && k>=count[i]; i++){
            k -= count[i];
        }
        
        return i;
    }
};