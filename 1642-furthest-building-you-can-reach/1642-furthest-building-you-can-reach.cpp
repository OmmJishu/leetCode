class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> need;
        
        for(int i = 1; i<heights.size(); i++){
            if(heights[i] > heights[i-1])
            {
                need.push(heights[i] - heights[i-1]);
                bricks -= (heights[i] - heights[i-1]);
                
                if(bricks < 0){
                    ladders--;
                    bricks += need.top();
                    need.pop();
                    if(bricks < 0 || ladders < 0)
                        return --i;
                }
            }
        }
        
        return heights.size()-1;
    }
};