class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it : arr) mp[it]++;
        sort(arr.begin(),arr.end());
        int cnt = 0, n = arr.size();
        
        for(int i = 0; i<n; i++){
            int num1 = arr[i], num2 = 2*arr[i];
            
            if(mp.find(num1) != mp.end() && mp.find(num2) != mp.end()){
                mp[num1]--;
                mp[num2]--;
                if(mp[num1] == 0) mp.erase(num1);
                if(mp[num2] == 0) mp.erase(num2);
                cnt += 1;
            }
        }
        
        return cnt == n/2 && mp.size() == 0;
    }
};