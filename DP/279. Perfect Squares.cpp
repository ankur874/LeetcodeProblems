class Solution {
public:
   int isPerfect(int n){
       int x=sqrt(n);
       if(x*x==n)return true;
       return false;
   }
    int numSquares(int n,vector<int>&dp,vector<int>&isPerDP){
        if(n<0){
            return INT_MAX;
        }
        if(n==0)return 0;
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=INT_MAX;
        for(int i=0;i<isPerDP.size();i++){
               ans=min(ans,numSquares(n-isPerDP[i],dp,isPerDP));
        }
        dp[n]=1+ans;
        return 1+ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        vector<int>isPerDP;
        for(int i=1;i<=n;i++){
            if(isPerfect(i)){
                isPerDP.push_back(i);
            }
        }
        // for(int val:isPerDP){
        //     cout<<val<<" ";
        // }
        return numSquares(n,dp,isPerDP);
    }
};