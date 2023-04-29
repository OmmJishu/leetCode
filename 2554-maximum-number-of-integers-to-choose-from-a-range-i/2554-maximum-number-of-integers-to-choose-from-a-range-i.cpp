class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(),banned.end());
        
        long long sum = 0,count = 0;
        for(int i = 1; i<=n; i++){
            if(binary_search(banned.begin(),banned.end(),i) == false){
                if(sum+i<=maxSum){
                    count++;
                    sum+=i;
                }
            }
        }
        return count;
    }
};