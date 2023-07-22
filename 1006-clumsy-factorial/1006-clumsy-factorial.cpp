class Solution {
public:
    int clumsy(int n) {
        vector<int> nums;
        
        for(int i = n; i>=1; i--)
            nums.push_back(i);
        
        stack<int> stk;
        char prevSign = '*';
        stk.push(nums[0]);
        
        for(int i = 1; i<nums.size(); i++){
            if(prevSign == '+'){
                stk.push(nums[i]);
                prevSign = '-';
            }
            else if(prevSign == '*'){
                int temp = stk.top();
                stk.pop();
                stk.push(temp*nums[i]);
                prevSign = '/';
            }
            else if(prevSign == '/'){
                int temp = stk.top();
                stk.pop();
                stk.push(temp/nums[i]);
                prevSign = '+';
            }
            else if(prevSign == '-'){
                stk.push(-1*nums[i]);
                prevSign = '*';
            }
            cout<<stk.top()<<" ";
        }
        
        int res = 0;
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        
        return res;
    }
};