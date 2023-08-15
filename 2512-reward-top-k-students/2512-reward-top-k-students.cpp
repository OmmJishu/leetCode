class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string,int> pos_feed, neg_feed;
        
        for(auto it : positive_feedback)
            pos_feed[it]++;
        for(auto it : negative_feedback)
            neg_feed[it]++;
        
        vector<vector<int>> store;
        
        for(int i = 0; i<student_id.size(); i++){
            report[i] += ' ';
            string s = "";
            int cnt = 0;
            for(int j = 0; j<report[i].size(); j++){
                if(report[i][j] == ' '){
                    if(pos_feed.find(s) != pos_feed.end()){
                        cnt += 3;
                    }
                    else if(neg_feed.find(s) != neg_feed.end()){
                        cnt -= 1;
                    }
                    
                    s = "";
                }
                else{
                    s += report[i][j];
                }
            }
            
            store.push_back({cnt,student_id[i]});
        }
        
        sort(store.begin(),store.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] > b[0])
                return true;
            else if(a[0] == b[0])
                return a[1] < b[1];
            return false;
        });
        
        vector<int> res(k);
        for(int i = 0; i<k; i++)
            res[i] = store[i][1];
        
        return res;
    }
};