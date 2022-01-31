class Solution {
public:
    int numDecodings(string s,vector<int>&dp) {
        if(s.length()<=0){
            return 1;
        }
        if(s.length()==1){
            return 1;
        }
        if(dp[s.length()]!=-1){
            return dp[s.length()];
        }
        int number1=s[0]-'0';
        int number2=number1*10+(s[1]-'0');
        int o1=0,o2=0;
        if(number1!=0){
            o1=numDecodings(s.substr(1),dp);
            if(number2>=10&&number2<=26){
               o2=numDecodings(s.substr(2),dp);
            }
        }else{
           dp[s.length()]=0;
           return 0;
        }
        dp[s.length()]= o1+o2;
        return  o1+o2;
    }
    int numDecodings(string s){
        vector<int>dp(s.length()+1,-1);
        return numDecodings(s,dp);
    }
};