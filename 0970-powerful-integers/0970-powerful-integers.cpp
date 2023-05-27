class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        map<int,int> mp1, mp2;
        
        // For x
        int i = 0, p=0;
        while(i<=bound){
            i = pow(x,p);
            if(i<=bound)
                mp1[i]++;
            if(mp1[i]>1){
                mp1[i]--;
                break;
            }
            p++;
        }
        
        // For y
        p = 0;
        i = 0;
        while(i<=bound){
            i = pow(y,p);
            if(i<=bound)
                mp2[i]++;
            if(mp2[i]>1){
                mp2[i]--;
                break;
            }
            p++;
        }
        
        set<int> res;
        for(auto it : mp1){
            int a = it.first;
            int req = bound - a;
            for(auto f : mp2){
                if(f.first <= req)
                    res.insert(a+f.first);
            }
        }
        
        vector<int> ans(res.begin(),res.end());
        return ans;
    }
};