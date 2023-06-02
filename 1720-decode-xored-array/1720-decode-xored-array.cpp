class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> arr(n+1);
        arr[0] = first;
        
        //Since that encoded[i] = arr[i] XOR arr[i+1], then arr[i+1] = encoded[i] XOR arr[i]
        for(int i = 0; i<n; i++){
            arr[i+1] = arr[i]^encoded[i];
        }
        
        return arr;
    }
};