class Solution {
public:
    bool equalFrequency(string word) {
       map<char,int>mp;
        for(auto it:word)
        {
            mp[it]++;
        }
        vector<int>arr;
        for(auto it:mp)
        {
            arr.push_back(it.second);
        }
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(n==1)
            return true;
        else if(arr[n-1]==1)
            return true;
        else if(arr[0]==arr[n-2] && arr[n-1]-arr[n-2]==1)
            return true;
        else if(arr[0]==1 && arr[1]==arr[n-1])
            return true;
        else
            return false;

    }
};