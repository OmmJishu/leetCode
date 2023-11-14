class Solution {
public:
int countPalindromicSubsequence(string s) {
int leftHash[26] = {0};
int rightHash[26] = {0};
for(auto it : s){
rightHash[it-'a']++;
}
int n = s.size();
int cnt = 0;
rightHash[s[0]-'a']--;
for(int i = 1; i<n-1; i++){
leftHash[s[i-1]-'a']++;
if(rightHash[s[i]-'a']>=0)
rightHash[s[i]-'a']--;
// cout<<leftHash[s[i]-'a']<<"  "<<rightHash[s[i]-'a']<<endl;
// cout<<"For index i = "<<i<<endl;
bool mark[26] = {false};
for(char ch = 'a'; ch<='z'; ch++){
// char ch = s[j];
int freqLeft = leftHash[ch-'a'];
int freqRight = rightHash[ch-'a'];
// cout<<"Freq Left of "<<ch<<" = "<<freqLeft<<"  And Freq right = "<<freqRight;
int mini = min(freqLeft,freqRight);
// cout<<"  And mini = "<<mini<<endl;
if(mini == 1 && mark[ch-'a'] == false){
cnt += mini;
mark[ch-'a'] = true;
}
}
// cout<<endl<<endl;
}
return cnt;
}
};