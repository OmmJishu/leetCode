vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
vector<vector<string>>ans;
unordered_set<string>dict(wordList.begin(),wordList.end());
if (dict.find(endWord) == dict.end()) return ans;
queue<vector<string>>q;
q.push({beginWord});
dict.erase(beginWord);
while (q.empty() == false){
int s = q.size();
vector<string>wordsUsed;
for (int i = 0; i < s; i++){
vector<string>path = q.front();
string word = q.front().back();
q.pop();
if (word == endWord){
ans.push_back(path);
continue;
}
for (int i = 0; i < word.size(); i++){
char original = word[i];
for (char c = 'a'; c <= 'z'; c++) {
word[i] = c;
if ( dict.find(word) != dict.end() ) {
path.push_back(word);
q.push(path);
wordsUsed.push_back(word);
path.pop_back();
}
}
word[i] = original;
}
}
for(auto it : wordsUsed) dict.erase(it);
} return ans;
}