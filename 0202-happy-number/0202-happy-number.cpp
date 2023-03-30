class Solution {
public:
    vector<int> save;
    bool isHappy(int n) {
        vector<int> store;
        while(n){
            store.push_back(n%10);
            n /= 10;
        }
        long long sum = 0;
        for(int i = 0; i<store.size(); i++){
            sum = sum + pow(store[i],2);
        }
        save.push_back(sum);
        sort(save.begin(),save.end());
        for(int i = 0; i<save.size()-1; i++){
            if(save[i] == save[i+1] && save[i]!=1)
                return false;
        }
        if(sum == 1)
            return true;
        else{
            return isHappy(sum);
        }
        return false;
    }
};