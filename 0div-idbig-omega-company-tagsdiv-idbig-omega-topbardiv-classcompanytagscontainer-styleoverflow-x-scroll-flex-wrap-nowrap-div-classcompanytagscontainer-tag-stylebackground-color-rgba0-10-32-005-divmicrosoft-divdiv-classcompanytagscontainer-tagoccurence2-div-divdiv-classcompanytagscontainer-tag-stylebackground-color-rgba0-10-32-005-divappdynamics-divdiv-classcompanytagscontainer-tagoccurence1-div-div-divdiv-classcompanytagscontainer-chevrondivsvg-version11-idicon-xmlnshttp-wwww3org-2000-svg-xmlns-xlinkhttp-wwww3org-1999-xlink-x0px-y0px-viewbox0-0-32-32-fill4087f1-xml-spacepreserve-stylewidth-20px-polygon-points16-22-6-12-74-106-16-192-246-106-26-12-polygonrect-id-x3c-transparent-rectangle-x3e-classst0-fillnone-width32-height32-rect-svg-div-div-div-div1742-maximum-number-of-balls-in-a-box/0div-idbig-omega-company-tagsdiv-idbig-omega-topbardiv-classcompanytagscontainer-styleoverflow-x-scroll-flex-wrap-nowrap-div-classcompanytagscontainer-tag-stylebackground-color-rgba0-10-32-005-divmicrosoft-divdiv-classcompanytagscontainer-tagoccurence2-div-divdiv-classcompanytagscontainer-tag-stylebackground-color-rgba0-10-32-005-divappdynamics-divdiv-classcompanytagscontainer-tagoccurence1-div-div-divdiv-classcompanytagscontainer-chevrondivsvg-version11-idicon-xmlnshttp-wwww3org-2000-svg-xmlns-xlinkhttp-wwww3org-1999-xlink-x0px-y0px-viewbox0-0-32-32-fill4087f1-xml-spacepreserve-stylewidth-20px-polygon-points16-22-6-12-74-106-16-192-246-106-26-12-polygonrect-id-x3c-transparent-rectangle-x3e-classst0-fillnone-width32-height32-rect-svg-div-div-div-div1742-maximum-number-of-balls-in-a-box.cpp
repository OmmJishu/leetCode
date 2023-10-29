class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int n = highLimit - lowLimit + 1;
        unordered_map<int,int> mp;
        
        for(int i = lowLimit; i<=highLimit; i++){
            int sum = 0;
            int num = i;
            while(num){
                sum += num%10;
                num /= 10;
            }
            mp[sum]++;
        }
        
        int maxi = INT_MIN;
        for(auto it : mp)
            maxi = max(maxi,it.second);
        
        return maxi;
    }
};