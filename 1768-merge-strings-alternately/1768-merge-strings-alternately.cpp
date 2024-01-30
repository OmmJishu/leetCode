class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        string store;
        int i = 0, j = 0;
    
        while(i<n1 && j<n2){
            store += word1[i++];
            store += word2[j++];
        }
        
        if(n1>n2)
            store.append(word1,i);
        store.append(word2,j);
        
        return store;
    }
};