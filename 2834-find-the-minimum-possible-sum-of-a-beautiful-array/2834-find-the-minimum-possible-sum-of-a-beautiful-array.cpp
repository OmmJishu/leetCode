class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_map<int, int> mp;
        long long sum = 0;
        
        int i = 1, cnt = 0;
        while(cnt<n){
            if(mp.find(target-i) != mp.end()){
                i++;
            }
            else{
                mp[i]++;
                cnt++;
                sum += i;
                i++;
            }
        }
    
        return sum;
    }
};