class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence = sentence + ' ';
        int ans = INT_MAX;
        int count = 0;
        
        for(int i = 0; i<sentence.size(); i++){
            string temp = "";
            while(sentence[i] != ' ')
                temp = temp + sentence[i++];
            count++;
            
            string temp2 = "";
            if(temp.size() >= searchWord.size()){
                for(int k = 0; k<searchWord.size(); k++){
                    temp2 = temp2 + temp[k];
                }
            }
            
            if(temp2 == searchWord)
                ans = min(ans,count);
        }
        cout<<ans<<"  ";
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};