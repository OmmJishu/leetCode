class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
       
        vector<string> res;
        if(n > target[target.size()-1])
            n = target[target.size()-1];
        
        int j = 0;
        for(int i = 1; i<=n; i++){
            int count = 0;
            if(i < target[j]){
                while(i < target[j]){
                    res.push_back("Push");
                    count++;
                    i++;
                }
                if(i==target[j]){
                    while(count--){
                        res.push_back("Pop");
                    }
                    res.push_back("Push");
                    j++;
                }
            }
            else{
                res.push_back("Push");
                j++;
            }
        }
        return res;
    }
};