class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(auto it : piles)
            q.push(it);
        
        for(int i = 0; i<k; i++){
            int num = q.top();
            q.pop();
            if(num%2 == 0)
                q.push(num/2);
            else
                q.push(1 + num/2);
        }
        
        int sum = 0;
        while(!q.empty()){
            sum += q.top();
            q.pop();
        }
        
        return sum;
    }
};