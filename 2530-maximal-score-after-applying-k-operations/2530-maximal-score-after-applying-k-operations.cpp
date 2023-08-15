class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> q;
        for(auto it : nums)
            q.push(it);
        
        for(int i = 0; i<k; i++){
            int num = q.top();
            q.pop();
            score += num;
            if(num%3 == 0)
                q.push(num/3);
            else
                q.push(1 + num/3);
        }
        
        return score;
    }
};