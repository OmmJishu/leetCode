class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> res;
        
        vector<int> markVowel(words.size(),0);
        int i = 0;
        for(auto it : words){
            if(check(it[0]) && check(it[it.size()-1])){
                markVowel[i] = 1;
            }
            i++;
        }
        
        vector<int> countVowel(markVowel.size()+1,0);
        countVowel[1] = markVowel[0];
        for(int i = 1; i<markVowel.size(); i++)
            countVowel[i+1] = markVowel[i] + countVowel[i];
        
        
        for(auto it : queries)
            res.push_back(countVowel[it[1]+1] - countVowel[it[0]]);
            
        return res;
    }

private:
    bool check(char c){ 
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' ||  c == 'u') 
            return true; 
        return false;
    }
};