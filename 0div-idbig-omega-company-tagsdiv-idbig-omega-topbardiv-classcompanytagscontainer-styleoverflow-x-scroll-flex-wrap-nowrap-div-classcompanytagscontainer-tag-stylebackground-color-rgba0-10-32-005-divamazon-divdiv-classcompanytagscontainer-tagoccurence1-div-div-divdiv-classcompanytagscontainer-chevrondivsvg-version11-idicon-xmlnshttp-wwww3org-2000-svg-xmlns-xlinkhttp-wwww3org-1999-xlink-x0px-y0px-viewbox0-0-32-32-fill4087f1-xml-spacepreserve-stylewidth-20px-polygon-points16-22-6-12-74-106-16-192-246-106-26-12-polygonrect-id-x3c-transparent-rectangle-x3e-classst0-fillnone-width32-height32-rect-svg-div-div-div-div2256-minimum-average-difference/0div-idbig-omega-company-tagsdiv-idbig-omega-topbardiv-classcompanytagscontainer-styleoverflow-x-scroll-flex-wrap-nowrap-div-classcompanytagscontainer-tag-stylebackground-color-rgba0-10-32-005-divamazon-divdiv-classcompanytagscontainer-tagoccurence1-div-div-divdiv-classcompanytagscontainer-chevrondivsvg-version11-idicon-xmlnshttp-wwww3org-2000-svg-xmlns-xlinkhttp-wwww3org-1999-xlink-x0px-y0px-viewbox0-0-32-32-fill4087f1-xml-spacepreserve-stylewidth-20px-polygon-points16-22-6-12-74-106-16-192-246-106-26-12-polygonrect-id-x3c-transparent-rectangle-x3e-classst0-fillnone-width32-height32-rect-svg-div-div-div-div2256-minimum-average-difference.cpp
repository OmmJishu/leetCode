class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long mini = INT_MAX;
        long suffixSum = accumulate(nums.begin(),nums.end(),0L);
        int a = 1;
        long prevSum = 0;
        int b = n-1;
        int miniIdx = 100001;
        
        for(int i = 0; i<n; i++){
            prevSum += nums[i];
            long prevAvg = prevSum/a;
            a++;
            suffixSum -= nums[i];
            long suffixAvg;
            if(suffixSum > 0)
                suffixAvg = suffixSum/(b);
            else
                suffixAvg = 0;
            b--;
            
            long diff = abs(prevAvg-suffixAvg);
            
            long prev = mini;
            mini = min(mini,diff);
            
            if(mini < prev && prev != INT_MAX)
                miniIdx = i;
        }
        
        return miniIdx == 100001 ? 0 : miniIdx;
    }
};