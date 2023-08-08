class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        cout<<cardPoints.size();
        int maxi = INT_MIN, n = cardPoints.size();
        int total = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int currWindow = accumulate(cardPoints.begin(),cardPoints.begin()+(n-k),0);
        
        maxi = max(maxi,total-currWindow);
        for(int i = 1; i+(n-k)<=n; i++){
            currWindow -= cardPoints[i-1];
            currWindow += cardPoints[i+(n-k)-1];
            maxi = max(maxi,total-currWindow);
        }
        
        return maxi;
    }
};