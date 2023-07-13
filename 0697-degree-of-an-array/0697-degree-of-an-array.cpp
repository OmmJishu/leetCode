class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        cout<<nums.size();
        
        unordered_map<int,int> mp;
        int mxFreq = INT_MIN;
        vector<int> element;
        
        for(auto it : nums) mp[it]++;
        
        if(mp.size() == nums.size()) return 1;
        
        for(auto it : mp)
            mxFreq = max(mxFreq,it.second);
        cout<<"  Mx Freq = "<<mxFreq;
        for(auto it : mp)
            if(it.second == mxFreq)
                element.push_back(it.first);
        
        int start = 0, end = 0;
        int ans = INT_MAX;
    
        for(int k = 0; k<element.size(); k++){
            for(int i = 0; i<nums.size(); i++){
                if(nums[i] == element[k]){
                    start = i;
                    break;
                }
            }

            for(int i = nums.size()-1; i>=0; i--){
                if(nums[i] == element[k]){
                    end = i;
                    break;
                }
            }
            
            ans = min(ans,end - start + 1);
        }
        
        return ans;
    }
};