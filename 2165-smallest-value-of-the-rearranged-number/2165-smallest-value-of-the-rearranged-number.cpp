class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0)
            return num;
        vector<int> store;
        long long int temp = abs(num);
        while(temp){
            int c = temp%10;
            store.push_back(c);
            temp=temp/10;
        }
        if(num < 0){
            sort(store.begin(), store.end(),greater<int>());
            string s = "";
            for(int i = 0; i<store.size(); i++){
                string a = to_string(store[i]);
                s = s + a;
            }
            long long int a = stoll(s);
            return -1*a;
        }
        
        sort(store.begin(), store.end());
        int countZero = 0;
        int zero = 0;
        if(store[0] == 0){
            int i = 0;
            while(store[i] == 0){
                countZero++;
                i++;
            }
            zero = countZero;
            while(countZero--){
                store.erase(store.begin());
            }
        }
        string s = "";
        string st = to_string(store[0]);
        s = s + st;
        while(zero--){
            s = s + '0';
        }
        for(int i = 1; i<store.size(); i++){
            string a = to_string(store[i]);
            s = s + a;
        }
        long long int a = stoll(s);
        return a;
    }
};