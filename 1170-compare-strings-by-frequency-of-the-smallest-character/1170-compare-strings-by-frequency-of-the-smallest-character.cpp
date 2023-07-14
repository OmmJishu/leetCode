class Solution {
public:
    int freq(string s){
        map<char,int> mp;
        for(auto it : s)
            mp[it]++;
        
        int f = 0;
        for(auto it : mp){
            f = it.second;
            break;
        }
        
        return f;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        
        vector<int> wordFreq;
        for(auto it : words){
            wordFreq.push_back(freq(it));
        }
        sort(wordFreq.begin(),wordFreq.end());
        
        int end = wordFreq.size();
        for(auto it : queries){
            int a = freq(it);
            
            // The upper_bound function searches for the first element in the sorted range [v.begin(), v.end()) that is greater than freq. It uses a binary search algorithm to find the position where this condition is true.
            //The result of upper_bound is an iterator pointing to the found element. It could be the iterator to the element itself if it exists, or the iterator to the next greater element if the element is not present in the vector.
            int j = upper_bound(wordFreq.begin(),wordFreq.end(), a) - wordFreq.begin();
            
            res.push_back(end-j);
        }
        
        return res;
    }
};