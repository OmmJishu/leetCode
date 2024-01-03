class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        vector<string> bnk;
        for(int i = 0; i<bank.size(); i++){
            string temp = bank[i];
            int cnt = 0;
            for(auto it : temp){
                if(it == '1'){
                    cnt++;
                    break;
                }
            }
            if(cnt > 0)
                bnk.push_back(temp);
        }
        
        if(bnk.size()==0)
            return 0;

        int ans = 0;
        for(int i = 0; i<bnk.size()-1; i++){
            string first = bnk[i];
            string second = bnk[i+1];
            int c1 = 0;
            int c2 = 0;
            for(auto it : first)
                if(it == '1')
                    c1++;
            for(auto it : second)
                if(it == '1')
                    c2++;
            ans = ans + c1*c2;
        }
        
        return ans;
    }
};