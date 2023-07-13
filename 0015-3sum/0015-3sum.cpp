class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int left = i + 1;
            int right = n - 1;
            
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate elements
                    while(left < right && nums[left] == nums[left + 1])
                        left++;
                    while(left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    left++;
                    right--;
                }
                else if(sum < 0)
                    left++;
                else
                    right--;
            }
        }
        
        return res;
    }
};



//  Code is correct For size == 3000  runtime is 2500 ms  That will definitely make TLE

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         cout<<nums.size();
//         sort(nums.begin(),nums.end());
        
//         for(int i = 0; i<nums.size(); i++){
//             unordered_map<int,int> mp;
//             if(i > 0 && nums[i] == nums[i - 1])
//                 continue;
            
//             int next = nums[i+1];
//             for(int j = i+1; j<nums.size(); j++){
                
//                 int twoSum = nums[i] + nums[j];
//                 int req = 0;
//                 if(twoSum != 0)  
//                     req = -1*twoSum;
        
//                 if(mp.find(req) != mp.end()){
//                     int ind1 = j;
//                     int ind2 = mp[req];
//                     if(ind1 != ind2){
//                         vector<int> temp(3,0);
//                         temp[0] = nums[i];
//                         temp[1] = nums[j];
//                         temp[2] = req;
//                         sort(temp.begin(),temp.end());
//                         res.push_back(temp);
//                     }
//                 }
//                 mp[nums[j]] = j;
//             }
//         }
        
//         set<vector<int>> st(res.begin(),res.end());
//         res.clear();
//         res.insert(res.end(),st.begin(),st.end());
//         return res;
//     }
// };