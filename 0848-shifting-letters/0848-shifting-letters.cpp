class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        cout<<s.size()<<" "<<shifts.size()<<endl;
        for(int i = 0; i<shifts.size(); i++){
            shifts[i] = shifts[i]%26;
        }
        
        for(int i = shifts.size()-2; i>=0; i--){
            shifts[i] = shifts[i]+shifts[i+1];
        }
        
        for(int i = 0; i<s.size(); i++){
            int a = shifts[i]%26;
            if(a+(s[i]-'a'-1) >= 25){
                int rem = a-25;
                a = rem+(s[i]-'a'-1);
                s[i] = 'a';
            }
            s[i] = s[i] + a;
        }
        
        return s;
    }
};