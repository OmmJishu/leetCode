class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        unsigned long long int prevNum = 0;
        for(int i = 0; i<word.size(); i++){
            unsigned long long int newNum = (prevNum * 10) +  word[i] - 48; 
            if (newNum % m == 0) 
                res.push_back(1);
            else 
                res.push_back(0);
            
            prevNum = newNum%m; 
        }
        return res;
    }
};