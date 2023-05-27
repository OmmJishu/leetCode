class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> str = {"999","888","777","666","555","444","333","222","111","000"};
        for(int i = 0; i<str.size(); i++){
            for(int j = 0; j<num.size()-2; j++){
                string temp = "";
                temp = temp + num[j] + num[j+1] + num[j+2];
                if(temp == str[i])
                    return str[i];
            }
        }
        return "";
    }
};