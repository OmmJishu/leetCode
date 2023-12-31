class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();
        int len = nums[0].size();
        
        for(auto it : queries){
            int idx = it[0];
            int j = it[1];
            
            priority_queue<pair<string,int>, vector<pair<string,int>>, greater<pair<string,int>>> pq;
            for(int i = 0; i<n; i++){
                string r = nums[i].substr(len-j, j);
                pq.push({r,i});
            }
            
            int curr = 1;
            while(!pq.empty()){
                if(curr == idx){
                    res.push_back(pq.top().second);
                    break;
                }
                curr++;
                pq.pop();
            }
        }
        
        return res;
    }
};