class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        vector<pair<int,pair<int,int>>> res;
        for(int i = 0; i<nums.size(); i++){
            int curr = nums[i];
            if(nums[i] == 0){
                int num = mapping[0];
                res.push_back({num,{i,curr}});
            }
            else{
                vector<int> store;
                while(nums[i]){
                    int c = nums[i]%10;
                    store.push_back(c);
                    nums[i] = nums[i]/10;
                }

                reverse(store.begin(),store.end());
                int num = 0;
                for(int k = 0; k<store.size(); k++){
                    int temp = mapping[store[k]];
                    num = 10*num + temp;
                }

                res.push_back({num,{i,curr}});
            }
        }
        
        sort(res.begin(),res.end());
        
        vector<int> result;
        for(int i = 0; i<res.size(); i++){
            result.push_back(res[i].second.second);
        }
        
        return result;
    }
};