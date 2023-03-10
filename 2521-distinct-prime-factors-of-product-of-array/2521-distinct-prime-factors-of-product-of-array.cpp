class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> st;
        for(int i = 0; i<nums.size(); i++){
            int c = 2;
            int n = nums[i];
            while(n > 1){
                if(n%c == 0){
                    st.insert(c);
                    n = n/c;
                }
                else
                    c++;
            }
        }
        return st.size();
    }
};