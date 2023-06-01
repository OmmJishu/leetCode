class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int> mp;
        for(int i = 0; i<score.size(); i++){
            mp[score[i]] = i;  // to map or save index w.r.to each score
        }
        vector<string> res(score.size(),"");
        sort(score.begin(),score.end(),greater<int>());
        
        for(int i = 0; i<score.size(); i++){
            if (i+1 == 1) {
                res[mp[score[i]]] = "Gold Medal"; // mp[score[i]] gives previous index and then rank score accordingly
            } 
            else if ( i+1 == 2) {
                res[mp[score[i]]] = "Silver Medal";
            } 
            else if (i+1 == 3) {    
                res[mp[score[i]]] = "Bronze Medal";
            } 
            else {
                res[mp[score[i]]] = to_string(i+1);
            }
        }
        return res;
    }
};