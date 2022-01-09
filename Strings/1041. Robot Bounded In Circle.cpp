class Solution {
public:
    bool isRobotBounded(string s) {
        char cd='N';
        int x=0;
        int y=0;
        for(int i=0;i<s.length();i++){
            if(cd=='N'){
                if(s[i]=='G'){
                   x++; 
                }else if(s[i]=='L'){
                    cd='W';
                }else if(s[i]=='R'){
                    cd='E';
                }
            }
            else if(cd=='S'){
                if(s[i]=='G'){
                    x--;
                }else if(s[i]=='L'){
                    cd='E';
                }else if(s[i]=='R'){
                    cd='W';
                }
            }
            else if(cd=='W'){
                if(s[i]=='G'){
                    y--;
                }else if(s[i]=='L'){
                    cd='S';
                }else if(s[i]=='R'){
                    cd='N';
                }
            }
            else if(cd=='E'){
                if(s[i]=='G'){
                   y++; 
                }else if(s[i]=='L'){
                    cd='N';
                }else if(s[i]=='R'){
                    cd='S';
                }
            }
         
        }
        char sd='N';
        for(int i=0;i<s.length();i++){
            if(s[i]=='G'){
                break;
            }
            if(sd=='N'){
                if(s[i]=='L'){
                    sd='W';
                }else{
                    sd='E';
                }
            }else if(sd=='S'){
                if(s[i]=='L'){
                    sd='E';
                }else{
                    sd='W';
                }
            }else if(sd=='E'){
                if(s[i]=='L'){
                    sd='N';
                }else{
                    sd='S';
                }
            }else if(sd=='W'){
                if(s[i]=='L'){
                    sd='S';
                }else{
                    sd='N';
                }
            }
        }
        if(x==0&&y==0){
            return true;
        }
        if('N'==cd){
            return false;
        }
        return true;
    }
};