//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string res = "";
  int n = src.size(), cnt = 1;
  
  for(int i = 1; i<n; i++){
      if(src[i] == src[i-1]){
          cnt++;
      }
      else{
          res += src[i-1];
          int num = cnt;
          res += to_string(num);
          cnt = 1;
      }
  }
  res += src[n-1];
  res += to_string(cnt);
  
  return res;
}     
 
