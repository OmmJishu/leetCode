class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int num = 0;
        for(int i = 0; i<nums1.size(); i++){
            for(int j = 0; j<nums2.size(); j++)
                if(nums1[i]==nums2[j])
                    return nums1[i];
        }
        
        if(nums1[0]<nums2[0])
            num = num*10 + nums1[0];
        else
            num = num*10 + nums2[0];
        
        if(num == nums1[0])
            num = num*10 + nums2[0];
        else
            num = num*10 + nums1[0];
        return num;
    }
};