//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int N, int k) 
    { 
        int maxLen = 0;
        int n = N;
        long long sum = 0;
        map<long long,int> mp;
        
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            if(sum == k){
                maxLen = max(maxLen,i+1);
            }
            long long remaining = sum-k;
            if(mp.find(remaining) != mp.end()){
                int len = i - mp[remaining];
                maxLen = max(maxLen,len);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends