class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        vector<pair<pair<int, int>, int>> v;
        
        for(int i = 0,j = skill.size()-1; i<skill.size()/2; i++,j--){
            v.push_back({{skill[i],skill[j]},skill[i]+skill[j]});
        }
        
        for(int i = 0; i<v.size()-1; i++){
            if(v[i].second != v[i+1].second)
                return -1;
        }
        
        long long res = 0;
        for(int i = 0; i<v.size(); i++){
            res = res + (v[i].first.first * v[i].first.second);
        }
        
        return res;
    }
};