class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int mini = INT_MIN;
        
        for(int i = nums.size()-1; i>=0; i--){
            if(nums[i] < mini)
                return true;
            else{
                while(!stk.empty() && stk.top() < nums[i]){
                    mini = stk.top();
                    stk.pop();
                }
            }
            stk.push(nums[i]);
        }
        
        return false;
    }
};