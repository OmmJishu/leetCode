class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        
        string digits = "123456789";
        int lowLen = to_string(low).length();
        int highLen = to_string(high).length();
        
        for (int len = lowLen; len <= highLen; len++) {
            for (int i = 0; i+len <= 9; i++) {
                int num = stoi(digits.substr(i, len));
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }
        
        return res;
    }
};

// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int> res;
        
//         string a = to_string(low);
//         int szA = a.size();
        
//         int arr[9] = {1,2,3,4,5,6,7,8,9};
        
//         while(low <= high){
//             for(int i = 0; i+szA<=9; i++){
//                 int temp = szA;
//                 int num = 0;
//                 int j = i;
//                 while(temp--){
//                     num = num*10+arr[j++];
//                 }
//                 res.push_back(num);
//                 if(num > high){
//                     res.pop_back();
//                     return res;
//                 }
//             }
//             low = res[res.size()-1];
//             szA++;
//         }
        
//         return res;
//     }
// };