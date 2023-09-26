class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> store(n,-1);
        stack<int> stk; // decreasing stack (Monotonic stack)
        
        for(int i = 0; i<2*n; i++){
            while(!stk.empty() && nums[i%n] > nums[stk.top()]){
                store[stk.top()] = nums[i%n];
                stk.pop();
            }
            stk.push(i%n);
        }
        
        return store;
    }
};