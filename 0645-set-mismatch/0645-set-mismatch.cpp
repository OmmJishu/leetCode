class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> store(n+1,0);
        
        for(auto it : nums){
            store[it]++;
            if(store[it] == 2){
               res.push_back(it);
            }
        }
        for(int i = 1; i<=n; i++){
            if(store[i] == 0){
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};