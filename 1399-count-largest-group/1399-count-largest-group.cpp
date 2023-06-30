class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> arr(n);
        for(int i = 1; i<=n; i++)
            arr[i-1] = digitSum(i);
        
        unordered_map<int,int> mp;
        int mxFreq = INT_MIN;
        for(auto it : arr){
            mp[it]++;
            mxFreq = max(mxFreq,mp[it]);
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