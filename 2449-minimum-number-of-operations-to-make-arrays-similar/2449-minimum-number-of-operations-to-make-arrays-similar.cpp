class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> evennums, oddnums, eventarget, oddtarget;
        
        for(auto it : nums){
            if(it%2 == 0) 
                evennums.push_back(it);
            else
                oddnums.push_back(it);
        }
        
        for(auto it : target){
            if(it%2 == 0) 
                eventarget.push_back(it);
            else
                oddtarget.push_back(it);
        }
        
        
        long long count = 0;
        sort(evennums.begin(),evennums.end());
        sort(eventarget.begin(),eventarget.end());
        sort(oddnums.begin(),oddnums.end());
        sort(oddtarget.begin(),oddtarget.end());
        
        for(int i =0;i<oddnums.size();i++){
            if(oddnums[i]<oddtarget[i]){
                count+= ((oddtarget[i]-oddnums[i])/2);
            }
        }
         for(int i =0;i<evennums.size();i++){
            if(evennums[i]<eventarget[i]){
                count+= ((eventarget[i]-evennums[i])/2);
            }
        }
        
        return count;
    }
};