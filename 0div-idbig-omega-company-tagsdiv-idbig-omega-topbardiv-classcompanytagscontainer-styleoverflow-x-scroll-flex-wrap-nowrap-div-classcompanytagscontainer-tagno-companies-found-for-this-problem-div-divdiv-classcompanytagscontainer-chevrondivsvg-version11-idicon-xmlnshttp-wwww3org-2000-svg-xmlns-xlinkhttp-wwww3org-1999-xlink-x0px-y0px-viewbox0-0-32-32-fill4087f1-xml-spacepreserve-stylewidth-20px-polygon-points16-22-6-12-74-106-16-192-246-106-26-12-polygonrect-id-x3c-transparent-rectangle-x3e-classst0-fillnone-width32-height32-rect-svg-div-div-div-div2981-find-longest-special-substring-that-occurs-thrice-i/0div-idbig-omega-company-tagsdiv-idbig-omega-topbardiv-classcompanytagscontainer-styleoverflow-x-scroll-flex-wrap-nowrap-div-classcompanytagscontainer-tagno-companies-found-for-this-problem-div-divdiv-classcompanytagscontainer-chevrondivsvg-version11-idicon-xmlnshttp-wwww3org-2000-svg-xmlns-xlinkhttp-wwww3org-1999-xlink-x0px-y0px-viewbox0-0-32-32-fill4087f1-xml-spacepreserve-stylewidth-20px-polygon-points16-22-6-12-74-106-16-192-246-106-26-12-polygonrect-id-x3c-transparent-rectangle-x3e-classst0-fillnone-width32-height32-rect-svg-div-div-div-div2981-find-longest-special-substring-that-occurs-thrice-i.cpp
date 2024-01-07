class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int maxi = -1;
        
    
        for(int m = 0; m<n; m++){
            string str = "";
            int i = m;
            while(i<=n-1){
                if(i>0&&s[i]!=s[i-1]){
                    str = "";
                }
                str += s[i++];
                int k = str.size();
                int cnt = 0;

                for(int j = 0; (j+k)<= n; j++){

                    string temp = "";
                    int r = j;
                    for(int p = 0; p<k; p++){
                        temp += s[r++];
                    }

                    if(str == temp){
                        cnt++;
                        if(cnt >= 3){
                            maxi = max(maxi, k);
                            break;
                        }
                    }
                }
            }
        }
        
        return maxi;
    }
};