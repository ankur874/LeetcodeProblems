class Solution {
public:

   //this is top-down approach
   //try to think of bottom-down and without dp
    int helper(vector<int>&cost,int step,vector<int>&dp){
         if(step>=cost.size()){
             return 0;
         }
         if(dp[step]!=-1){
             return dp[step];
         }
         int o1=helper(cost,step+1,dp)+cost[step];
         int o2=helper(cost,step+2,dp)+cost[step];
         dp[step]= min(o1,o2);
         return dp[step];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+2,-1);
        //top down approach
        // int o1,o2;
        // if(dp[0]==-1){
        //     o1=helper(cost,0,dp);
        // }
        // if(dp[1]==-1){
        //    o2=helper(cost,1,dp);
        // }
        //bottom up approach
        int n=cost.size();
        dp[n]=0;
        dp[n+1]=0;
          for(int i=n-1;i>=0;i--){
              dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
          }
        return min(dp[0],dp[1]);
    }
};