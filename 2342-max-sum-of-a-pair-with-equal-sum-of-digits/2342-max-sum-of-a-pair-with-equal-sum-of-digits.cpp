class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int maxi = -1;
        map<int,multiset<int>> mp;
        
        for(int i = 0; i<nums.size(); i++){
            int sum = digitSum(nums[i]);
            mp[sum].insert(nums[i]);
        }
        
        for(auto it : mp){
            if(it.second.size() > 1){
                auto itr = it.second.end();
                itr--;
                int last = *itr;
                itr--;
                last += *itr;
                
                maxi = max(maxi,last);
            }
        }
        
        return maxi;
    }
    
private:
    int digitSum(int a){
        int sum = 0;
        while(a){
            sum += a%10;
            a /= 10;
        }
        
        return sum;
    }
};