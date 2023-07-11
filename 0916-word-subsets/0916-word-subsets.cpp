class Solution {
public:
    vector<int> findFreq(string s){
        vector<int> freq(26,0);
        
        for(auto it : s)
            freq[it-'a']++;
        
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector <int> max_freq(26,0);
        
        for(auto it : words2){
            vector<int> freq = findFreq(it);
            
            for(int j = 0; j<26; j++){
                max_freq[j] = max(max_freq[j], freq[j]);
            }
        }
        
        for(auto it : words1){
            vector<int> freq = findFreq(it);
            
            bool flag = true;
            for(int j = 0; j<26; j++){
                if(freq[j] < max_freq[j]){ 
                    flag = false;
                    break;
                }
            }
            
            if(flag == true)
                res.push_back(it);
        }
        
        return res;
    }
};