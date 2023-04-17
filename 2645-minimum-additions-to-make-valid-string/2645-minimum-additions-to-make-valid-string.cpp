class Solution {
public:
    int addMinimum(string word) {
        int ans = 0;
        int i = 0, n = word.size();
        while(i < n){
            if(word[i] == 'a')
            {
                if(i+1 < n && word[i+1] == 'b')
                {
                    if(i+2 < n && word[i+2] == 'c') 
                        i += 3;
                    else{ 
                        i += 2; 
                        ans++; 
                    }
                }
                else if(i+1 < n && word[i+1] == 'c')
                { 
                    i += 2;
                    ans += 1;
                }
                else 
                { 
                    i++; 
                    ans+=2; 
                }
            }
            else if(word[i] == 'b')
            {
                if(i+1 < n && word[i+1] == 'c'){
                    i += 2; 
                    ans += 1;
                }
                else{ 
                    i++; 
                    ans += 2;
                }
            }
            else
            { 
                i++; 
                ans += 2;
            }
        }
        return ans;
    }
};