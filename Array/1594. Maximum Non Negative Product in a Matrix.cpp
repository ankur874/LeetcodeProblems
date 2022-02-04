class Solution {
public:
   
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int mod=1e9+7;
        int m=grid[0].size();
        vector<vector<pair<long,long>>>dp(n,vector<pair<long,long>>(m));
        dp[n-1][m-1].first=grid[n-1][m-1];
        dp[n-1][m-1].second=grid[n-1][m-1];
        for(int i=m-2;i>=0;i--){
            dp[n-1][i].first=grid[n-1][i]*dp[n-1][i+1].first;
            dp[n-1][i].second=grid[n-1][i]*dp[n-1][i+1].second;
        }
         for(int i=n-2;i>=0;i--){
            dp[i][m-1].first=grid[i][m-1]*dp[i+1][m-1].first;
             dp[i][m-1].second=grid[i][m-1]*dp[i+1][m-1].second;
        }
        //  for(int i=m-2;i>=0;i--){
        //     cout<<dp[n-1][i]<<" ";
        // }
        // cout<<endl;
        //  for(int i=n-2;i>=0;i--){
        //     cout<<dp[i][m-1]<<" ";
        // }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                // dp[i][j]=max(grid[i][j]*dp[i][j+1],grid[i][j]*dp[i+1][j]);
                long o1=max(grid[i][j]*dp[i][j+1].first,grid[i][j]*dp[i+1][j].first);
                long o2=max(grid[i][j]*dp[i][j+1].second,grid[i][j]*dp[i+1][j].second);
                long o3=min(grid[i][j]*dp[i][j+1].first,grid[i][j]*dp[i+1][j].first);
                long o4=min(grid[i][j]*dp[i][j+1].second,grid[i][j]*dp[i+1][j].second);
                dp[i][j].first=max(o1,o2);
                dp[i][j].second=min(o3,o4);
            }
        }
        if(dp[0][0].first<0){
            return -1;
        }
        return max(dp[0][0].first,dp[0][0].second)%mod;
    }
};