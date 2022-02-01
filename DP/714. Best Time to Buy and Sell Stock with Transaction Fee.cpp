class Solution {
public:
    int helper(vector<int>&prices,bool isTaken,int fee,int day,vector<vector<int>>&dp){
        if(day>=prices.size()){
            return 0;
        }
        if(dp[day][isTaken]!=-1){
            return dp[day][isTaken];
        }
        if(isTaken){
            int o1=helper(prices,isTaken,fee,day+1,dp);
            int o2=helper(prices,false,fee,day+1,dp)+prices[day]-fee;
            dp[day][isTaken]= max(o1,o2);
            return dp[day][isTaken];
        }
        int o1=helper(prices,isTaken,fee,day+1,dp);
        int o2=helper(prices,true,fee,day+1,dp)-prices[day];
        dp[day][isTaken]= max(o1,o2);
        return dp[day][isTaken];
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return helper(prices,false,fee,0,dp);
    }
};