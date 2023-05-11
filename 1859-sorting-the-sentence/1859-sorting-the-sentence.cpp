class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int,string>> store;
        
        for(int i = 0; i<s.size(); i++){
            string temp = "";
            int num = 0;
            while(s[i] != ' '){
                if(isdigit(s[i])){
                    num = num + s[i] - '0';
                    break;
                }
                temp = temp + s[i];
                i++;
            }
            if(num>0)
                store.push_back({num,temp});
        }
        sort(store.begin(),store.end());
        string ans = "";
        for(auto it : store)
            ans = ans + it.second + ' ';
        
        ans.pop_back();
        return ans;
    }
};