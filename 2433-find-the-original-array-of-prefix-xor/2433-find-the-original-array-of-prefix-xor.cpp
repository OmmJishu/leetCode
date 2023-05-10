class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size());
        int prev = 0;
        
        for(int i = 1; i<pref.size(); i++){
            prev = prev ^ pref[i-1];
            pref[i] = prev ^ pref[i];
        }
        return pref;
    }
};