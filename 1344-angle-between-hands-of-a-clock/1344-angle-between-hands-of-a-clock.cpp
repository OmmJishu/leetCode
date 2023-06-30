class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Min 60 minutes then hour = 30 degree
        
        double minDegree = minutes*6;
        double hourDegree = 0;
        
        if(hour != 12)
            hourDegree = double(hour)*double(30) + double(30*minutes)/double(60);
        
        if(hour == 12)
            hourDegree = double(30*minutes)/double(60);
        
        if(abs(hourDegree - minDegree) > 180)
            return 360 - abs(hourDegree - minDegree);
        
        return abs(hourDegree - minDegree);
    }
};