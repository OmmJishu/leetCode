class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        
        int start = 0, end = n; 
        while(start<end){
            int mid = start + (end-start)/2;
            if(citations[mid] >= n-mid){
                end = mid;
            }
            else{
                start = mid+1;
            }
        }
        
        return n-start;
    }
};