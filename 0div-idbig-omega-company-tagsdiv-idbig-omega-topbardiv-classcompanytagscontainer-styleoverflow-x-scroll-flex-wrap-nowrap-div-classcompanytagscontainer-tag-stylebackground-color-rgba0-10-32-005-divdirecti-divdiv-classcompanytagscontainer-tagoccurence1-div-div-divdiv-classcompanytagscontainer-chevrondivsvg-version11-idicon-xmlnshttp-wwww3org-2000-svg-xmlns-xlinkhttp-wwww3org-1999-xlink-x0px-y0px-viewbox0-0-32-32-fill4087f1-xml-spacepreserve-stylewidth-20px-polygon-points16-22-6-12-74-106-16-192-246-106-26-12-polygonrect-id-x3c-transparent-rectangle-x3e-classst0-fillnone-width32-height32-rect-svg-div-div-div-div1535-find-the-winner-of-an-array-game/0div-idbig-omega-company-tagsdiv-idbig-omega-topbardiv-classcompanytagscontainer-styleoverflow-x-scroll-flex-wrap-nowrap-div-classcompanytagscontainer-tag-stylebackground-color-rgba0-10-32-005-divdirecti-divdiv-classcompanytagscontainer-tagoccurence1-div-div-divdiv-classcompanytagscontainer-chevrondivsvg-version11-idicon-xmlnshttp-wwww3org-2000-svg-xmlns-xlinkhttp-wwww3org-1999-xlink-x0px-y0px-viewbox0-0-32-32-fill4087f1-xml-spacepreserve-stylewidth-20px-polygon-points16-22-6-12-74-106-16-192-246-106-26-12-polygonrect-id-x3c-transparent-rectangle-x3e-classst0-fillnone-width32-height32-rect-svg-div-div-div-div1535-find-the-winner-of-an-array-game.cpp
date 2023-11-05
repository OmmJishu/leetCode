class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k >= arr.size())
            return *max_element(arr.begin(),arr.end());
        
        int i = 0, j = 1;
        unordered_map<int,int> mp;
        
        while(i <= arr.size()){
            if(arr[i] >= arr[j]){
                arr.push_back(arr[j]) ;
                mp[arr[i]]++ ;
                if(mp[arr[i]] == k)
                    return arr[i] ;
            }
            else{
                arr.push_back(arr[i]) ;
                i = j;
                mp[arr[i]]++ ;
                if(mp[arr[i]] == k)
                    return arr[i] ;
            }
            j++;
        }
        
        return 0;
    }
};