class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1)
            return 1;
        
        int n = chars.size();
        int i = 0,j = 0;
        while(i<n){
           int count=1;
           while(i<n-1 && chars[i]==chars[i+1]){
               i++;
               count++;
           }
           chars[j++]=chars[i++];
           if(count>1){
               string s=to_string(count);
               for(auto c: s)
               chars[j++]=c;
           }
       }
       return j;
    }
};