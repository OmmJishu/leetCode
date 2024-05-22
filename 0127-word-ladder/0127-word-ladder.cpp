class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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