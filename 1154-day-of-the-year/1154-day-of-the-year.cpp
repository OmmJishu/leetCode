class Solution {
public:
    bool checkLeap(int year){
        if (year % 400 == 0) 
            return true;
        else if (year % 100 == 0)
            false;
        else if (year % 4 == 0) 
            return true;
        return false;
    }
    int dayOfYear(string date) {
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
        string s = "";
        s = s+date[0]+date[1]+date[2]+date[3];
        int year = stoi(s);
        if(checkLeap(year))
            days[1] = 29;
        
        string m = "";
        m = m+date[5]+date[6];
        int month = stoi(m);
        
        string d = "";
        d = d+date[8]+date[9];
        int dy = stoi(d);
        
        int count = 0;
        for(int i = 0; i<month-1; i++)
            count = count+days[i];
        return count+dy;
    }
};