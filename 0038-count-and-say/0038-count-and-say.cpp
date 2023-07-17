class Solution {
public: 
    string countAndSay(int n) {
        if(n == 1)
            return "1";
    
        string res = "11";
        int a = 2;
        
        while(a < n){       
            int cnt = 1;
            vector<pair<int,char>> nums;
                      
            for(int i = 0; i<res.size(); i++){
                if(res[i] == res[i+1]){
                    cnt++;
                }
                else{
                    nums.push_back({cnt,res[i]});
                    cnt = 1;
                }
            }
            
            res = "";
            for(int i = 0;  i<nums.size(); i++){
                res += to_string(nums[i].first) + nums[i].second;
            }
            
            a++;
        }
        
        return res;
    }
};