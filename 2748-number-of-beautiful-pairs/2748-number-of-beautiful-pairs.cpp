class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                int a = nums[i];
                while(a >= 10){
                    a = a/10;
                }
                int b = nums[j]%10;
                if(gcd(a,b) == 1)
                    count++;
            }
        }
        return count;
    }
    
private:
    int gcd(int x, int y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
    }
};