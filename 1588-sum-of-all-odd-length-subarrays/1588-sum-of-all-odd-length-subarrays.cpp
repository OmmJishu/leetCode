class Solution {
public:
    
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        
        int a = 1;
        while(a<=arr.size()){
            int sum = 0;
            for(int i = 0; i+a <= arr.size(); i++){
                int b = a, j = i;
                while(b--){
                    sum = sum + arr[j++];
                } 
            }
            res = res + sum;
            a = a+2;
        }
        return res;
    }
};