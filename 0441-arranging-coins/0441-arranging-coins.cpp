class Solution {
public:
    int arrangeCoins(int n) {
        int a = n;
        int count = 0;
        int i = 1;
        long long s = 0;
        while(i <= n){
            s = s + i;
            if(s <= n){
                count++;
            }
            else
                break;
            i++;
        }
        return count;
    }
};