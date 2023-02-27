class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> store;
        
        for(int i = 0; i<s.size(); i++){
            string st = "";
            if(isdigit(s[i])){
                while(isdigit(s[i])){
                    if(!isdigit(s[i]))
                        break;
                    st = st + s[i];
                    i++;
                }
                store.push_back(stoi(st));
            }
            else
                continue;
        }
        for(int i = 0; i<store.size()-1; i++){
            if(store[i] >= store[i+1])
                return false;
        }
        return true;
    }
};