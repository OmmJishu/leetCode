class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int cnt = 0;
        for(int i = 1; i<nums.size(); i++){ //  if there is more than one point where nums[i] < nums[i-1] then can not sort by right shift
            if(nums[i] < nums[i-1])
                cnt++;
            if(cnt == 2)
                return -1;
        }
        
        
        int pivot = findPivotIndex(nums);
        if(pivot == 0)  return 0; // already sorted
           
        vector<int> temp(nums.begin()+pivot,nums.end()); // making unrotated
        for(int i = 0; i<pivot; i++)
            temp.push_back(nums[i]);
        
        for(int i = 0; i<temp.size()-1; i++)
            if(temp[i] > temp[i+1])
                return -1;
        
        return nums.size()-pivot;
    }
    
private:
    int findPivotIndex(vector<int>& nums) { // gives index where nums is rotated
        int left = 0;
        int right = nums.size()-1;

        while (left < right) {
            int mid = left + (right-left)/2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};