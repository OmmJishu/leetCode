class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int a = coordinates[0]-'0'-48;
        int b = coordinates[1]-'0';
        
        if((a+b)%2 == 0)
            return false;
        return true;
    }
};