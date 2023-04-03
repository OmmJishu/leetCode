class Solution {
public:
    bool digitCount(string num) {
        int count = 0;
        for(int i = 0; i<num.size(); i++){
            int count = 0;
            char d = num[i]-'0';
            int comp = int(d);
            for(int j = 0; j<num.size(); j++){
                char s = num[j]-'0';
                int a = int(s);
                if(a==i){
                    count++;
                }
            }
            if(count != comp)
                return false;
        }
        return true;
    }
};