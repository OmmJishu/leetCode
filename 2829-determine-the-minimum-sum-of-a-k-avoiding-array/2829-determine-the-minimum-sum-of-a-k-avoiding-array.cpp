class Solution {
public:
    int minimumSum(int n, int k) {
        int num = 1;
        vector<int> res;
        unordered_map<int,int> mp;
        
        while(res.size() < n){
            if(mp.find(num) == mp.end()){
                res.push_back(num);
                mp[k-num]++;
            }
            num++;
        }
        
        return accumulate(res.begin(),res.end(),0);
    }
};