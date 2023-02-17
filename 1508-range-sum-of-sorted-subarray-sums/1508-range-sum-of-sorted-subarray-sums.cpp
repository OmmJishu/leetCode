class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> store;
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = i+0; j<n; j++){
                sum = sum + nums[j];
                store.push_back(sum);
            }
        }
        sort(store.begin(),store.end());
        unsigned long long int res = 0;
        for(int i = left-1; i<=right-1; i++)
            res = res+store[i];
        
        return res%1000000007;
    }
};