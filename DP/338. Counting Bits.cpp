class Solution {
public:
    vector<int> countBits(int n) {
     
        vector<int>dp(n+1);
           if(n<1)return dp;
        int lastPower=2;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if(lastPower*2==i){
                lastPower=i;
                dp[i]=1;
            }else{
                dp[i]=1+dp[i-lastPower];
            }
            
        }
        return dp;
    }
};