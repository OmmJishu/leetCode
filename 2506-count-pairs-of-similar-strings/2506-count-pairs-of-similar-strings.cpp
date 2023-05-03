class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<string> store;
        int count = 0;
        
        for(auto it : words){
            set<char> st;
            for(auto ch : it)
                st.insert(ch);
            
            string s = "";
            for(auto m : st)
                s = s + m;
            
            store.push_back(s);
        }
        
        for(int i = 0; i<store.size(); i++){
            for(int j = i+1; j<store.size(); j++){
                if(store[i] == store[j])
                    count++;
            }
        }
        return count;
    }
};