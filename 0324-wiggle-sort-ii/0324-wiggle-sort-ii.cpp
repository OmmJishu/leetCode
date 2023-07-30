class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        vector<int> first, second;
        
        if(n%2 == 0){
            for(int i = (n/2)-1; i>=0; i--)
                first.push_back(nums[i]);

            for(int i = n-1; i>=n/2; i--)
                second.push_back(nums[i]);
        }
        else{
            for(int i = (n/2); i>=0; i--)
                first.push_back(nums[i]);

            for(int i = n-1; i>n/2; i--)
                second.push_back(nums[i]);
        }
        
        nums.clear();
        int a = first.size(), b = second.size();
        
        for(int i = 0; i<max(a,b); i++){
            if(i<a)
                nums.push_back(first[i]);
            if(i<b)
                nums.push_back(second[i]);
        }
    }
};