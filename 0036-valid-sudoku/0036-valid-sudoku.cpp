class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& nums) {
        
        for(int i = 0; i<9; i++){
            unordered_map<int,int> mp;
            for(int j = 0; j<9; j++){
                if(nums[i][j] == '.') continue;
                if(mp[nums[i][j] - '0'] > 0)
                    return false;
                mp[nums[i][j]-'0']++;
            }
        }
        
        for(int i = 0; i<9; i++){
            unordered_map<int,int> mp;
            for(int j = 0; j<9; j++){
                if(nums[j][i] == '.') continue;
                if(mp[nums[j][i] - '0'] > 0)
                    return false;
                mp[nums[j][i] - '0']++;
            }
        }
        
        for(int i = 0; i<9; i += 3){
            for(int j = 0; j<9; j += 3){
                unordered_map<int,int> mp;
                for(int p = i; p<(i+3); p++){
                    for(int k = j; k<(j+3); k++){
                        if(nums[p][k] == '.') continue;
                        if(mp[nums[p][k] - '0'] > 0) 
                            return false;
                        mp[nums[p][k] - '0']++;
                    }
                }
            }
        }
        
        return true;
    }
};