class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> first,last;
        for(int i = 0; i < flowers.size(); i++){
            first.push_back(flowers[i][0]);
            last.push_back(flowers[i][1]);
        }
        sort(begin(first),end(first));
        sort(begin(last),end(last));
        
        vector<int> res;
        for(int i = 0; i<people.size(); i++){
            int idx1 = upper_bound(first.begin(),first.end(),people[i])-first.begin();
            int idx2 = lower_bound(last.begin(),last.end(),people[i])-last.begin();
            cout<<idx1<<" "<<idx2<<"    ";
            res.push_back(idx1-idx2);
        }
        
        return res;
    }
};