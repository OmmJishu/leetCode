class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene)
            return 0;
        set<string> st{bank.begin(),bank.end()};
        
        queue<string> q;
        q.push(startGene);
        int number = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                if(curr == endGene)
                    return number;
                st.erase(curr);
                for(int i = 0; i<8; i++){
                    string temp = curr;
                    temp[i] = 'A';
                    if(st.count(temp))
                        q.push(temp);
                    temp[i] = 'C';
                    if(st.count(temp))
                        q.push(temp);
                    temp[i] = 'G';
                    if(st.count(temp))
                        q.push(temp);
                    temp[i] = 'T';
                    if(st.count(temp))
                        q.push(temp);
                        
                }
            }
            number++;
        }
        
        return -1;
    }
};