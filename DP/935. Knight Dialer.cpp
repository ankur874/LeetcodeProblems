class Solution {
public:
    int mod=1e9+7;
    long dp[5001][4][3];
   long  dfs(int n,int i,int j){
        if(i<0||j<0||i>3||j>2){
            return 0;
        }
        if(i==3&&j==0)return 0;
        if(i==3&&j==2)return 0;
        if(n==1)return 1;
         if(dp[n][i][j]!=-1){
             return dp[n][i][j];
         }
        long a=dfs(n-1,i-2,j-1)%mod;
        long b=dfs(n-1,i-2,j+1)%mod;
        long c=dfs(n-1,i+2,j-1)%mod;
        long d=dfs(n-1,i+2,j+1)%mod;
        long e=dfs(n-1,i-1,j+2)%mod;
        long f=dfs(n-1,i+1,j+2)%mod;
        long g=dfs(n-1,i-1,j-2)%mod;
        long h=dfs(n-1,i+1,j-2)%mod;
        dp[n][i][j]= (a+b+c+d+e+f+g+h)%mod;
       return dp[n][i][j];
    }
    int knightDialer(int n) {
        memset(dp,-1,sizeof(dp));
        long  res=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                res=(res%mod+dfs(n,i,j)%mod)%mod;
            }
        }
        return res;
    }
};