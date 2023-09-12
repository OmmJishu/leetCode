class Solution {
public:
    int minDeletions(string s) {
        vector<int> temp;
        map<char,int> mp;
        for(auto it : s)
            mp[it]++;
        for(auto it : mp)
            temp.push_back(it.second);
        sort(temp.begin(),temp.end(),greater<int>());
        
        int ans = 0;
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] == 0) 
                break; 

            if (temp[i] >= temp[i-1]) {
                int curr = temp[i]; 
                temp[i] = max(0, temp[i-1] - 1); 
                ans += curr - temp[i]; 
            }
        }
       
        return ans;
    }
};