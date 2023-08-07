class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int start = 0, end = cheeseSlices;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            int jumbo = mid;
            int small = cheeseSlices - mid;
            
            if(4*jumbo + 2*small == tomatoSlices)
                return {jumbo,small};
            
            else if(4*jumbo + 2*small < tomatoSlices)
                start = mid+1;
            else
                end = mid-1;
        }
        return {};
    }
};