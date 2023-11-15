class Solution {
public:
    int balancedStringSplit(string s) {
        int findL = 0, cnt = 0;
        
        for(auto it : s){
            if(it == 'L'){
                findL++;
            }
            else{
                findL--;
            }
            
            if(findL == 0){
                cnt++;
            }
        }
        
        return cnt;
    }
};