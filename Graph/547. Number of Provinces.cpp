class Solution {
public:
   void dfs(vector<vector<int>>&isConnected,int r,vector<bool>&visited,int n,int m){
       visited[r]=true;
       for(int i=0;i<n;i++){
           if(isConnected[i][r]==1&&!visited[i]){
               dfs(isConnected,i,visited,n,m);
           }
       }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        int ans=0;
        vector<bool>visited(n);
        for(int i=0;i<n;i++){
                if(!visited[i]){
                    dfs(isConnected,i,visited,n,m);
                    ans++;
                }
        }
        return ans;
    }
};