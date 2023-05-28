class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> res;
        for(int i = 100; i<=998; i = i+2){
            int temp = i;
            int a = temp%10;
            temp = temp/10;
            int b = temp%10;
            temp = temp/10;
            int c = temp%10;
            
            for(int p = 0; p<digits.size(); p++)
            {
                if(digits[p] == c)
                {
                    for(int j = 0; j<digits.size(); j++)
                    {
                        if(digits[j] == b && j != p)
                        {
                            for(int k = 0; k<digits.size(); k++)
                            {
                                if(digits[k] == a && k != j && k != p)
                                {
                                    res.insert(c*100+b*10+a);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        vector<int> ans(res.begin(),res.end());
        return ans;
    }
};