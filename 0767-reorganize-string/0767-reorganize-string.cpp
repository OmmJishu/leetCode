class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for(auto it : s)
            mp[it]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        
        string res = "";
        while(pq.size() > 1){
            auto it = pq.top();  pq.pop();
            auto it1 = pq.top();  pq.pop();
            
            res += it.second;
            res += it1.second;
            
            int a = --it.first;
            int b = --it1.first;
            
            if(a > 0)  pq.push({a,it.second});
            if(b > 0)  pq.push({b,it1.second});
        }
        
        if(pq.size() == 1){
            auto it = pq.top();
            pq.pop();
            if(it.first > 1)
                return "";
            else
                res += it.second;
        }
        
        return res;
    }
};