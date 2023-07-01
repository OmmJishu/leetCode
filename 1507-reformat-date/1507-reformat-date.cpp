class Solution {
public:
    string reformatDate(string date) {
        map<string,string> mp;
        mp["Jan"] = "01";
        mp["Feb"] = "02";
        mp["Mar"] = "03";
        mp["Apr"] = "04";
        mp["May"] = "05";
        mp["Jun"] = "06";
        mp["Jul"] = "07";
        mp["Aug"] = "08";
        mp["Sep"] = "09";
        mp["Oct"] = "10";
        mp["Nov"] = "11";
        mp["Dec"] = "12";
        
        string day = "";
        string month = "";
        string year = "";
        if(date.size() == 12){
            day = day + '0' + date[0];
            month = month + date[4] + date[5] + date[6];
            year = year + date[8] + date[9] + date[10] + date[11]; 
        }
        
        if(date.size() == 13){
            day = day + date[0] + date[1];
            month = month + date[5] + date[6] + date[7];
            year = year + date[9] + date[10] + date[11] + date[12]; 
        }
        
        string res = "";
        
        res = res + year + '-' + mp[month] + '-' + day; 
        
        return res;
    }
};