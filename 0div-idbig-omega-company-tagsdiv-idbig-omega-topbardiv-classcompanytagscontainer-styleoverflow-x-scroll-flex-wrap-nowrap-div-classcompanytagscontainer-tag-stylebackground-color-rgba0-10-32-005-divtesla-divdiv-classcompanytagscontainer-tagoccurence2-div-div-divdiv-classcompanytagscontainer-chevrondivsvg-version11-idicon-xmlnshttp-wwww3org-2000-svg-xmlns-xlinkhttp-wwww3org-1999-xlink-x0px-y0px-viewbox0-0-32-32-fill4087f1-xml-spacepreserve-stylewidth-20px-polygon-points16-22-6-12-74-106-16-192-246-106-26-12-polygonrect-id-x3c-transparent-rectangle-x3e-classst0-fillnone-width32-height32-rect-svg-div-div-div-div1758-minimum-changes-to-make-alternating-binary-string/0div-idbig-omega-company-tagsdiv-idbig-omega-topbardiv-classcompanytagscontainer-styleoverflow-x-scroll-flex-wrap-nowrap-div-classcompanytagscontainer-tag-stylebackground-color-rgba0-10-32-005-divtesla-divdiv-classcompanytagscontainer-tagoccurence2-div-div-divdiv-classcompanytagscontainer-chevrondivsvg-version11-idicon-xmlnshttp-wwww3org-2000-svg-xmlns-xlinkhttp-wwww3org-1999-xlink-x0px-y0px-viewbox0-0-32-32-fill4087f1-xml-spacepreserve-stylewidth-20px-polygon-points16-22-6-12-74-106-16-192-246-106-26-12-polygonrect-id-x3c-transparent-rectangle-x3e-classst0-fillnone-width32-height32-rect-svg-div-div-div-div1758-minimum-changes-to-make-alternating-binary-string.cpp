class Solution {
public:
    int minOperations(string s) {
        int cnt = 0, n = s.size(), ans = INT_MAX;
        vector<char> arr(n,'0');
        for(int i = 1; i<n; i+=2)
            arr[i] = '1';

        for(int i = 0; i<n; i++){
            if(s[i] != arr[i])
                cnt++;
        }
        ans = min(ans,cnt);
        
        for(int i = 1; i<n; i+=2)
            arr[i] = '0';
        for(int i = 0; i<n; i+=2)
            arr[i] = '1';
        
        cnt = 0;
        for(int i = 0; i<n; i++){
            if(s[i] != arr[i])
                cnt++;
        }
        ans = min(ans,cnt);
        
        return ans;
    }
};