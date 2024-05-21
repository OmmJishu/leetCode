class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[start] <= nums[mid]){
                if(target>=nums[start] && target <= nums[mid])
                    end = mid;
                else
                    start = mid+1;
            }
            else{
                if(target >= nums[mid] && target <= nums[end])
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        
        return -1;
    }
};


// Find middle point mid = (l + h)/2
// If key is present at middle point, return mid.
// Else If arr[l..mid] is sorted
// a) If key to be searched lies in range from arr[l]
// to arr[mid], recur for arr[l..mid].
// b) Else recur for arr[mid+1..h]
// Else (arr[mid+1..h] must be sorted)
// a) If key to be searched lies in range from arr[mid+1]
// to arr[h], recur for arr[mid+1..h].
// b) Else recur for arr[l..mid]