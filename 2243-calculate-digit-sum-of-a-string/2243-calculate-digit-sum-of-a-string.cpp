class Solution {
public:
    string digitSum(string s, int k) {
        while ((int) s.size() > k) {
            int sum = 0;
            string temp = "";
            int count = 0;
            for (int i = 0; i < (int) s.size(); i++) {
                sum += (s[i] - '0');
                ++count;
                if (count == k) {
                    temp += to_string(sum);
                    sum = 0;
                    count = 0;
                }
            }
            if (count > 0) {
                temp += to_string(sum);
            }
            s = temp;
        }
        return s;
    }
};