class Solution {
public:
    int count(string s){
        int countt = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' ')
                countt++;
        }
        return countt+1;
    }
    int mostWordsFound(vector<string>& sentences) {
        int mx = INT_MIN;
        for(int i = 0; i<sentences.size(); i++){
            mx = max(mx,count(sentences[i]));
        }
        return mx;
    }
};