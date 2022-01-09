class Solution {
public:
    int dp[80][80][80];
    int helper(vector<vector<int>>&grid,int r,int c1,int c2){
        int n=grid.size();
        int m=grid[0].size();
        if(r==n)return 0;
        if(dp[r][c1][c2]!=-1){return dp[r][c1][c2];};
        int ans=INT_MIN;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int C1=c1+i;
                int C2=c2+j;
                if(C1>=0&&C2>=0&&C1<m&&C2<m){
                    ans=max(ans,helper(grid,r+1,C1,C2));
                }
            }
        }
        if(c1==c2){
            ans+=grid[r][c1];
        }else{
            ans+=(grid[r][c1]+grid[r][c2]);
        }
        dp[r][c1][c2]=ans;
        return ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        for(int i=0;i<80;i++){
            for(int j=0;j<80;j++){
              for(int k=0;k<80;k++){
                dp[i][j][k]=-1;
            }    
            }
        }
        int n=grid.size();
        int m=grid[0].size();
        cout<<n<<" "<<m;
        return helper(grid,0,0,m-1);
    }
};