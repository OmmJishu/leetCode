class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxdist = 0;
        int j = -1;
        for(int i = 0; i<seats.size(); i++){
            if(seats[i] == 0){
                continue;
            }
            
            if(j == -1)
                maxdist = max(maxdist,i);
            else{
                maxdist = max(maxdist,(i-j)/2);
            }
            j = i;
        }
        
        if(seats[seats.size()-1] == 0){
            maxdist = max(maxdist,int(seats.size()-j-1));
        }
        
        return maxdist;
    }
};