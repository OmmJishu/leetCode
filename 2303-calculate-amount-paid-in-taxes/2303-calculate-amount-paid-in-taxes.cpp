class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double res = 0;
        if(income == 0)
            return 0;
        int prev = 0;
        for(int i = 0; i<brackets.size(); i++){
            int money = min(income, brackets[i][0]);
            res = res + ((money - prev)*brackets[i][1])/100.00;
            if(brackets[i][0] >= income)
                break;
            prev = brackets[i][0];
        }
        return res;
    }
};