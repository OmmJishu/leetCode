//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            string curr = q.front().first;
            int level = q.front().second;
            q.pop();
            int len = curr.size();
            
            if(curr == endWord)
                return level;
            
            for(int i = 0; i<len; i++){
                string temp = curr;
                for(char ch = 'a'; ch<='z'; ch++){
                    temp[i] = ch;
                    if(st.find(temp) != st.end()){
                        q.push({temp,level+1});
                        st.erase(temp);
                    }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends