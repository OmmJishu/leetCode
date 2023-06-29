class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int n = citations.size();
        vector<int> temp(n);
        for(int i = 0; i<n; i++)
            temp[i] = i+1;
        
        int res = 0;
        int start = 0, end = n;
        while(start<end){
            int mid = start + (end-start)/2;
            if(citations[mid] >= temp[mid]){
                res = temp[mid];
                start = mid+1;
            }
            else if(citations[mid] < temp[mid]){
                end = mid;
            }
        }
        
        return res;
    }
};