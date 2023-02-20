class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res;
        
        for(int i = 0; i<n1; i++){
            for(int j = 0; j<n2; j++){
                if(nums2[j] == nums1[i]){
                    int temp = j;
                    int num = nums2[j];
                    int count = 0;
                    while(j<n2){
                        if(nums2[j] > num){
                            res.push_back(nums2[j]);
                            count++;
                            break;
                        }
                        else
                            j++;
                    }
                    if(count == 0)
                        res.push_back(-1);
                }
            }
        }
        return res;
    }
};