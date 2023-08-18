class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) 
            return false; 
            
        unordered_map<char,int> mp;
        for(auto it : s1)
            mp[it]++;
        
        int k = s1.size();
        
        unordered_map<char,int> temp;
        for(int i = 0; i<k; i++)
            temp[s2[i]]++;
        
        int cnt = 0;
        for(auto it : mp){
            if(temp.find(it.first) == temp.end()){
                break;
            }
            else{
                if(it.second != temp[it.first]){
                    break;
                }
                else
                    cnt++;
            }
        }
        
        if(cnt == mp.size())
            return true;
        
        
        for(int i = 1; i+k<=s2.size(); i++){
            temp[s2[i-1]]--;
            if(temp[s2[i-1]] == 0)
                temp.erase(s2[i-1]);
            
            temp[s2[i+k-1]]++;
            
            int c = 0;
            for(auto it : mp){
                if(temp.find(it.first) == temp.end()){
                    break;
                }
                else{
                    if(it.second != temp[it.first]){
                        break;
                    }
                    else
                        c++;
                }
            }
            
            if(c == mp.size())
                return true;
        }
        
        return false;
    }
};