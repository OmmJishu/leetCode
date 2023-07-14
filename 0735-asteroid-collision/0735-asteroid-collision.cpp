class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        int start = 0, end = asteroids.size()-1;
    
        while(start <= end){
            if(asteroids[start] > 0 || stk.empty()){
                stk.push(asteroids[start]);
            }
            else{
                while(!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroids[start]))
                    stk.pop();
                
                if(!stk.empty() && stk.top() == abs(asteroids[start]))
                    stk.pop();
                
                else if(stk.empty() || stk.top() < 0){   // Most important  stk.empty() || stk.top() < 0  order matters here
                        stk.push(asteroids[start]);
                }   
            }
            
            start++;
        }
       
        vector<int> res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(),res.end());
        
        return res;
    }
};