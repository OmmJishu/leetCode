class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        int cnt = 0;
        while(pq.top() > 0){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if(a > 0 && b == 0)
                break;
            pq.push(--a);
            pq.push(--b);
            cnt++;
        }
        
        return cnt;
    }
};