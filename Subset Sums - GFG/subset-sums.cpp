//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    private:
    vector<int> res;
    void findSum(int idx, int sum, vector<int> arr, int N){
        if(idx >= N){
            res.push_back(sum);
            return;
        }
        
        // pick that indexed element
        findSum(idx + 1, sum + arr[idx], arr, N);
        
        // NOT pick that indexed element
        findSum(idx + 1, sum, arr, N);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        findSum(0, 0, arr, N);
        sort(begin(res),end(res));
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends