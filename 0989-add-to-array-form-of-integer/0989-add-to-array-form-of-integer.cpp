class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        vector<int> temp;
        vector<int> res(num.size(),0);
        vector<int> querry(num.size(),0);
        
        while(k){
            temp.push_back(k%10);
            k /= 10;
        }
        
        // for i = 0
        int s = num[0] + temp[0];
        if(s > 9){
            res[0] = s%10;
            s /= 10;
            querry[0] = s;
        }
        else{
            res[0] = s;
        }
        
        int i;
        
        for(i = 1; i<num.size(); i++){
            int sum = 0;
            if(i<=temp.size()-1)
                sum += num[i] + temp[i] + querry[i-1];
            else
                sum += num[i] + querry[i-1];
            
            if(sum > 9){
                res[i] = sum%10;
                sum /= 10;
                querry[i] = sum;
            }
            else{
                res[i] = sum;
            }
        }
        
        if(i < temp.size()){
            while(i <= temp.size()-1){
                int sum = temp[i] + querry[i-1];
                if(sum > 9){
                    res.push_back(sum%10);
                    sum /= 10;
                    querry.push_back(sum);
                    i++;
                }
                else{
                    res.push_back(sum);
                    querry.push_back(0);
                    i++;
                }
            }
        }
        
    
        if(querry[querry.size()-1] > 0)
            res.push_back(querry[querry.size()-1]);
        
        reverse(res.begin(),res.end());
            
        return res;
    }
};