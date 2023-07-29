class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        unordered_map<int,int> mp;
        mp[0] = 0;
        
        for(int i = 0; i<time.size(); i++){
            int rem = time[i]%60;
            int get = (60-rem)%60;
            if(mp.find(get) != mp.end()){
                count += mp[get];
            }
            mp[rem]++;
        }
        
        return count;
    }
};