struct PairHash {
    template <class T1, class T2>
    size_t operator()(const pair<T1,T2> &p) const{
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<pair<int,int>,int, PairHash> mp;
        
        int row = 0, col = 0;
        mp[{row,col}]++;
        for(int i = 0; i<path.size(); i++){
            if(path[i] == 'N'){
                row++;
                mp[{row,col}]++;
                if(mp[{row,col}] == 2) return true;
            }
            else if(path[i] == 'S'){
                row--;
                mp[{row,col}]++;
                if(mp[{row,col}] == 2) return true;
            }
            else if(path[i] == 'E'){
                col++;
                mp[{row,col}]++;
                if(mp[{row,col}] == 2) return true;
            }
            else if(path[i] == 'W'){
                col--;
                mp[{row,col}]++;
                if(mp[{row,col}] == 2) return true;
            }
        }
        
        return false;
    }
};