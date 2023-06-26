class Solution {
public:
    string categorizeBox(long long length, long long width, long long height, long long mass) {
        // unsigned long long volume = length*width*height;
        string bulky = "";
        string heavy = "";
        string res = "";
        
        if(length >= 10000 || width >= 10000 || height >= 10000 || (length*width*height) >= 1000000000)
            bulky = bulky + "Bulky";
        if(mass >= 100)
            heavy = heavy + "Heavy";
        
        if(bulky.size()>0 && heavy.size()>0)
            res = res + "Both";
        else if(bulky.size()==0 && heavy.size()==0)
        res = res + "Neither";
        else if(bulky.size()>0 && heavy.size()==0)
            res = res + "Bulky";
        else if(bulky.size()==0 && heavy.size()>0)
            res = res + "Heavy";
        
        return res;
    }
};