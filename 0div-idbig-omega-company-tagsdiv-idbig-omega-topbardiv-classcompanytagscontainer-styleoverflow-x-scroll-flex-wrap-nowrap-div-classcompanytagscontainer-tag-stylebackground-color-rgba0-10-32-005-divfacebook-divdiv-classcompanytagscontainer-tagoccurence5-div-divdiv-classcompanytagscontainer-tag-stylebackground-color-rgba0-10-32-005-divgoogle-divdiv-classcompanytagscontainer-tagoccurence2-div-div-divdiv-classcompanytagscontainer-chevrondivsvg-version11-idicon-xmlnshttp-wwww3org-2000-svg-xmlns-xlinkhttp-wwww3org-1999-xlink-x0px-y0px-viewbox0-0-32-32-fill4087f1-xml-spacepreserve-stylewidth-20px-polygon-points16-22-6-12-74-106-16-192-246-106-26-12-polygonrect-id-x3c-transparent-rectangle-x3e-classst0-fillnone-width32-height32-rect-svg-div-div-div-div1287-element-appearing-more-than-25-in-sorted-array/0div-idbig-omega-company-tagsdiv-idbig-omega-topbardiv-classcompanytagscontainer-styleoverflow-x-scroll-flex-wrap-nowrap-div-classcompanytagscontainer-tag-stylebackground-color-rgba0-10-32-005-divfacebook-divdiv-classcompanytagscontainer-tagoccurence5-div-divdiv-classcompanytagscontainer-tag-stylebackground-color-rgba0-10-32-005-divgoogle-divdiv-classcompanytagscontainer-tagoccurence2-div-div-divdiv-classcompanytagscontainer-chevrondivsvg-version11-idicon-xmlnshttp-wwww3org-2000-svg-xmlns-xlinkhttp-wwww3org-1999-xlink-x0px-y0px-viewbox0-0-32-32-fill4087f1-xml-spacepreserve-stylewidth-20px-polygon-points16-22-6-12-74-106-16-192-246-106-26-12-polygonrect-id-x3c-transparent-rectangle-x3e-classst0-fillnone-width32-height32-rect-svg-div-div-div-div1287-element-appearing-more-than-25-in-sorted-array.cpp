class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return arr[0];

        int cnt = 1;
        for(int i = 1; i<n; i++){
            if(arr[i] != arr[i-1]){
                if(cnt > n/4)
                    return arr[i-1];
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        if(cnt > n/4)
            return arr[n-1];
        
        return 0;
    }
};