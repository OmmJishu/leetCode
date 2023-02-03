class Solution {
public:
    int sumBase(int n, int k) {
        int ans=0;
        while(n>0){
            int c = n%k;
            ans += c;
            n = n/k;
        }
        return ans;
    }
};