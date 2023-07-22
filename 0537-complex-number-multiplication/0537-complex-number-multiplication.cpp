class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string res = "";
        int a1 = real(num1);
        int a2 = real(num2);
        int b1 = complex(num1);
        int b2 = complex(num2);
        
        res = res + to_string(a1*a2-b1*b2)+'+'+to_string(a1*b2+a2*b1)+'i' ;
        
        return res ;
    }

private:
    int real(string str){
        int i = 0 ;
        string real = "" ;
        
        while(str[i]!='+'){
            real += str[i] ;
            i++ ;
        }
        return stoi(real) ;
    }
    
    int complex(string str){
        int i = 0 ;
        string complex = "" ;
        
        while(str[i]!='+'){
            i++ ;
        }
        
        i++ ;
        
        while(str[i]!='i'){
            complex += str[i] ;
            i++ ;
        }
        
        return stoi(complex) ;
    }
};