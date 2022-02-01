class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
       vector<int>dp(n+1,0);
       dp[0]=1;
       for(int i=1;i<=n;i++){
           int maxP=9;
           int ans=9;
           int p=i-1;
           while(p--){
              ans=ans*maxP;
              maxP--;
           }
           dp[i]=dp[i-1]+ans;
       }
       return dp[n];
    }
};