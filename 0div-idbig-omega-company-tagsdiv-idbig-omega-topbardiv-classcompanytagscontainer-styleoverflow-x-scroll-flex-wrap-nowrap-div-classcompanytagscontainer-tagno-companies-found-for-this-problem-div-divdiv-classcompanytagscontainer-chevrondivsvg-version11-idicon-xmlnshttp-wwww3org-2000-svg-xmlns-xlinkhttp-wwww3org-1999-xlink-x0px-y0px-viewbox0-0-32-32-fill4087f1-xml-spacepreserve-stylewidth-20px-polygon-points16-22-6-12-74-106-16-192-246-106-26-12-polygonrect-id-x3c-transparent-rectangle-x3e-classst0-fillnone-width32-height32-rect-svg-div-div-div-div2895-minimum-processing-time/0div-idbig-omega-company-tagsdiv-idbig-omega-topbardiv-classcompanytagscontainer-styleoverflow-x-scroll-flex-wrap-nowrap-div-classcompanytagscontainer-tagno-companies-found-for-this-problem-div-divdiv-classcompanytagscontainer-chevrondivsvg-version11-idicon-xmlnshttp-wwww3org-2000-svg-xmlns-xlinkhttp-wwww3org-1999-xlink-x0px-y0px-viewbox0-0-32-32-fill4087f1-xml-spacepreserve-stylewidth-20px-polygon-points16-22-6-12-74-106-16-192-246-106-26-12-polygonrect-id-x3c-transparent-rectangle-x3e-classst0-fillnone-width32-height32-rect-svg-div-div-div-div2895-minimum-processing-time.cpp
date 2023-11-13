class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& tasks) {
        sort(pt.begin(),pt.end());
        sort(tasks.begin(),tasks.end());
        
        
        int time = INT_MIN;
        int j = 0;
        for(int i = tasks.size()-1; i>=0; i-=4){
            int curr = INT_MIN;
            curr = max(curr,max(pt[j]+tasks[i],max(pt[j]+tasks[i-1],max(pt[j]+tasks[i-2],pt[j]+tasks[i-3]))));
            time = max(time,curr);
            j++;
        }
        
        return time;
    }
};