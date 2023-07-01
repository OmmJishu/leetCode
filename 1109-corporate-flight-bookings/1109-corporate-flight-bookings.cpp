class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n,0);
        
        for(auto it : bookings){
            // int start = it[0]-1;
            // int end = it[1];
            // int add = it[2];
        
            res[it[0]-1] += it[2];
            if(it[1]<n)
                res[it[1]] -= it[2]; 
        }
        
        for(int i = 1; i<n; i++)
            res[i] += res[i-1];
        
        return res;
    }
};


/*Since ranges are continuous, what if we add reservations to the first flight in the range, and remove them after the last flight in range? We can then use the running sum to update reservations for all flights.*/