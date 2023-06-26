class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        cout<<arr.size();
        int sum = accumulate(arr.begin(),arr.begin()+k,0);
        if(sum/k >= threshold) 
            count++;
        for(int i = 1; i+k<=arr.size(); i++){
            sum = sum-arr[i-1] +arr[i+k-1];
            if(sum/k >= threshold) 
                count++;
        }
        return count;
    }
};