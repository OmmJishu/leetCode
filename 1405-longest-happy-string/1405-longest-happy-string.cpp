class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int,char>> pq;
        if(a > 0)
            pq.push({a,'a'});
        if(b > 0)
            pq.push({b,'b'});
        if(c > 0)
            pq.push({c,'c'});
        
        string res = "";
        
        while(pq.size() > 1){
            auto it = pq.top(); pq.pop();
            auto it1 = pq.top(); pq.pop();
            
            if(it.first >= 2){
                res += it.second;
                res += it.second;
                it.first -= 2;
            }
            else{
                res += it.second;
                it.first -= 1;
            }
            
            if(it1.first >= 2 && it1.first >= it.first){
                res += it1.second;
                res += it1.second;
                it1.first -= 2;
            }
            else{
                res += it1.second;
                it1.first -= 1;
            }
            
            if(it.first > 0)
                pq.push({it.first,it.second});
            if(it1.first > 0)
                pq.push({it1.first,it1.second});
        }
        
        if(pq.size() == 1){
            auto it = pq.top(); pq.pop();
            if(it.first >= 2){
                res += it.second;
                res += it.second;
            }
            else{
                res += it.second;
            }
        }
     
        return res;
    }
};