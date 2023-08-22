using ll = long long;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> st(nums.begin(),nums.end());
        long long sum = (ll(k)*(ll(k+1)))/ll(2);
        
        for(auto it : st){
            if(it <= k){
                sum -= it;
                sum += k+1;
                k++;
            }
            else
                break;
        }
        
        return sum;
    }
};