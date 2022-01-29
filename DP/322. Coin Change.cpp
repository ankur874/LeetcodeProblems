class Solution {
public:
    //brute force with memoization
    // int coinChange(vector<int>& coins, int amount, vector<int>&dp) {
    //     if(amount==0){
    //         return 0;
    //     }
    //     if(dp[amount]!=-1){
    //         return dp[amount];
    //     }
    //     int ans=INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //         if(amount-coins[i]>=0){
    //         int sa=coinChange(coins,amount-coins[i],dp);
    //         if(sa!=-1){
    //             ans=min(ans,sa+1);
    //         }
    //         }
    //     }
    //     dp[amount]=ans==INT_MAX?-1:ans;
    //     return dp[amount];
    // }
    //dp tabular
    int coinChange(vector<int>&coins,int amount){
        //--------------------------------------------------
        //vector<int>dp(amount+1,-1);
        //return coinChange(coins,amount,dp);
        //---------------------------------------------------
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0){
                    dp[i][j]=1e5;
                }else if(j==0){
                    dp[i][j]=0;
                }else if(j-coins[i-1]<0){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
            }
        }
        return dp[n][amount]>1e4?-1:dp[n][amount];
    }
};