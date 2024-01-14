class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> mp1, mp2;
        for(auto it : word1) mp1[it]++;
        for(auto it : word2) mp2[it]++;
        
        vector<int> num1, num2;
        for(auto it : mp1){
            if(mp2[it.first] == 0)
                return false;
            num1.push_back(it.second);
            num2.push_back(mp2[it.first]);
        }
        
        sort(begin(num1),end(num1));
        sort(begin(num2),end(num2));
        
        return num1 == num2;
    }
};