class Solution {
public:
    int largestInteger(int num) {
        vector<int> even;
        vector<int> odd;
        vector<int> store;
        int temp = num;
        while(temp){
            int c = temp%10;
            store.push_back(c);
            if(c%2 == 0)
                even.push_back(c);
            else
                odd.push_back(c);
            temp /= 10;
        }
        sort(even.begin(),even.end(),greater<int>());
        sort(odd.begin(),odd.end(),greater<int>());
        reverse(store.begin(),store.end());
        int newNum = 0,p = 0, j = 0;
        for(int i = 0; i<store.size(); i++){
            if(store[i]%2 == 0)
                newNum = newNum*10 + even[p++];
            else
                newNum = newNum*10 + odd[j++];
        }
        return newNum;
    }
};