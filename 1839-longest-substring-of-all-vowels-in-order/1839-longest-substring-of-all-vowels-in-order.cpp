class Solution {
public:
    int longestBeautifulSubstring(string word) {
        cout<<word.size();
        int maxi = INT_MIN;
        int i = 0, j = 0;
        
        set<char> st;
        for(i = 1, j = 0; i<word.size(); i++){
            if(word[i] >= word[i-1])
                st.insert(word[i-1]);
            else{
                st.insert(word[i-1]);
                if(st.size() == 5)
                    maxi = max(maxi,i-j);
                
                st.clear();
                j = i;
            }
        }
        
        st.insert(word[i-1]);
        if(st.size() == 5)
            maxi = max(maxi,i-j);
        
        return maxi == INT_MIN ? 0 : maxi;
    }
};