class Solution {
public:
    int countLargestGroup(int n) {
        
        unordered_map<int,int> mp;
        int mxFreq = INT_MIN;
        for(int i = 1; i<=n; i++){
            int a = digitSum(i);
            mp[a]++;
            mxFreq = max(mxFreq,mp[a]);
        }
        
        int count = 0;
        for(auto it : mp)
            if(it.second == mxFreq)
                count++;
        
        return count;
    }

    private:
    int digitSum(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
};