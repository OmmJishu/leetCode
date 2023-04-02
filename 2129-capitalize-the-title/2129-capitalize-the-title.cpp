class Solution {
public:
    string capitalizeTitle(string title) {
        for(int i = 0; i<title.size(); i++){
            if(title[i]>='A' && title[i]<='Z')
                title[i] = title[i] + 32;
        }
        for(int i = 0; i<title.size(); i++){
            if((title[i]>='a' && title[i] <='z') && (title[i+1]>='a' && title[i+1] <='z') && (title[i+2]>='a' && title[i+2] <='z')){
                title[i] = title[i] - 32;
                int j;
                for(j = i+3; j<title.size(); j++)
                    if(title[j]==' ')
                        break;
                i = j;
            }
        }
        return title;
    }
};