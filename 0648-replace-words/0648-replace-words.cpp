class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        cout<<dictionary.size()<<"  "<<sentence.size();
        string res = "";
        unordered_map<string,int> mp;
        int sz = INT_MIN;
        
        for(auto it : dictionary){
            mp[it] = it.size();
            sz = max(sz,mp[it]);
        }
        
        sentence += ' ';
        string temp = "";
        
        for(auto it : sentence){
            if(it != ' ')
                temp += it;
            else{
                int a = temp.size();
                int currsz = min(sz,a);
                bool find = false;
                for(int i = 1; i<=currsz; i++){
                    string r = temp.substr(0,i);
                    if(mp.find(r) != mp.end()){
                        res += r + (' ');
                        find = true;
                        break;
                    }
                }
                if(find == false)
                    res += temp + (' ');
                
                temp = "";
            }
        }
        res.pop_back();
        
        return res;
    }
};