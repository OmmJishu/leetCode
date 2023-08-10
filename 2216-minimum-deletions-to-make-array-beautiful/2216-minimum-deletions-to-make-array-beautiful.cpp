class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int> stk;
        
        int cnt = 0;
        for(int i = 0; i<nums.size()-1; i++){
            int idx = i-cnt; // denotes the index of nums[i] if its previous deleted elements was remove then its position would be i-cnt
            if(nums[i] == nums[i+1] && idx%2==0){
                cnt++;
            }
        }
        
        if((nums.size()-cnt)%2 == 1)  // if modified array has size ODD so need to delete one more element
            cnt++;
    
        return cnt;
    }
};


// can be understood by this 
// modified   1 2 2 3 3
// index      0 1 2 3 4   now we do not have i%2==0 but length is NOT Even so delete one more