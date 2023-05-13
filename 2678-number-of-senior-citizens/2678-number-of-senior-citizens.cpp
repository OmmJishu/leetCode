class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(int i = 0; i<details.size(); i++){
            string age = "";
            age = age + details[i][11] + details[i][12];
            if((age[0]>= '6' && age[1]>='0') && age != "60")
                count++;
        }
        return count;
    }
};