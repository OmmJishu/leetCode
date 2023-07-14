class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        int moves = 0, mid;
        
        if(n%2 == 0)
            mid = nums[n/2];
        else
            mid = nums[(n/2)+1];
    
        for(int i = 0; i<=n; i++){
            moves += abs(mid - nums[i]);
        }
        
        return moves;
    }
};