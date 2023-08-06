class Solution {
public:
    int accountBalanceAfterPurchase(int A) {
        if(A%10 <= 4){
            return 100-(A-(A%10));
        }
        return 100-(A+(10-A%10));
    }
};