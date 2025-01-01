class Solution {
public:
    int maxScore(string s) {
        int total1 = 0;
        for(auto it : s) if(it == '1') total1++;
        
        int cnt0 = 0, maxi = INT_MIN;
        
        for(int i = 0; i<s.size()-1; i++){
            char it = s[i];
            if(it =='0') cnt0++;
            else if(it == '1') total1--;
            
            maxi = max(maxi,cnt0+total1);
        }
        
        return maxi;
    }
};