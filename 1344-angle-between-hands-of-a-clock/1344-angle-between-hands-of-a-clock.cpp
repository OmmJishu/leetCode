class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minDegree = minutes*6;
        if(hour == 12) hour = 0;
        double hourDegree = double(hour)*double(30) + double(30*minutes)/double(60);
        return min(abs(hourDegree - minDegree),360 - abs(hourDegree - minDegree));
    }
};