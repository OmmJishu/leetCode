class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        
        for(int i = 0; i<asteroids.size(); i++){
            if(asteroids[i] > mass){
                return false;
            }
            else if(asteroids[i] <= mass){
                mass += asteroids[i];
            }
        }
        
        return true;
    }
};