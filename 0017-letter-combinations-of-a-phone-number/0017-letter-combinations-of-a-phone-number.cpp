class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        
        unordered_map<char,string> mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        
        vector<string> res;
        res.push_back("");
        
        for(auto it : digits){
            vector<string> temp;
            for(auto ch : mp[it]){
                for(auto s : res)
                    temp.push_back(s+ch);
            }
            res.swap(temp);
        }
        
        return res;
    }
};