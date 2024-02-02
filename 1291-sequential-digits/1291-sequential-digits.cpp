class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(char i = '1'; i<='9'; i++){
            string temp = "";
            temp += i;
            for(char ch = i+1; ch<='9'; ch++){
                temp += ch;
                int num = stoi(temp);
                if(num>high) break;
                if(num>=low && num<=high)
                    res.push_back(num);
            }
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};