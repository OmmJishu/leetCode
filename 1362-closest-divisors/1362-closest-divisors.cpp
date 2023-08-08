class Solution {
public:
    vector<int> closestDivisors(int num) {
        long long a = num+1;
        vector<long long> divA;
        findDivisors(a,divA);
        sort(divA.begin(),divA.end());
        // for(auto it : divA)
        //     cout<<it<<" ";
        
        long long b = num+2;
        vector<long long> divB;
        findDivisors(b,divB);
        sort(divB.begin(),divB.end()); 
        // cout<<endl;
        // for(auto it : divB)
        //     cout<<it<<" ";
        
        vector<long long> first; vector<long long> second;
        
        
        
        for(int i = 0; i<divA.size(); i++){
            if(divA[i]*divA[i] == a){
                first.push_back(divA[i]);
                first.push_back(divA[i]);
                break;
            }
            else if(divA[i]*divA[i] > a){
                break;
            }
        }
        
        if(first.size() == 0){
            int mid = divA.size()/2;
            first.push_back(divA[mid-1]);
            first.push_back(divA[mid]);
        }
        
        // cout<<endl<<first[0]<<" "<<first[1]<<endl;
        
        
        
        for(int i = 0; i<divB.size(); i++){
            if(divB[i]*divB[i] == b){
                second.push_back(divB[i]);
                second.push_back(divB[i]);
                break;
            }
            else if(divB[i]*divB[i] > b){
                break;
            }
        }
        
        if(second.size() == 0){
            int mid = divB.size()/2;
            second.push_back(divB[mid-1]);
            second.push_back(divB[mid]);
        }
        
        // cout<<endl<<second[0]<<" "<<second[1]<<endl;
        
        vector<int> c; c.push_back(int(first[0])); c.push_back(int(first[1]));
        vector<int> d = {int(second[0]), int(second[1])};
        
        
        return (abs(first[0]-first[1]) < abs(second[0]-second[1])) ? c : d;
        // return first;
    }
    
private:
    void findDivisors(long long x, vector<long long>& divA){
        for(int i = 1; i<=sqrt(x); i++){
            if(x%i == 0){
                divA.push_back(i);
                if (i != x / i) 
                    divA.push_back(x / i);
            }
        }
    }
};