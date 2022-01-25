class Solution {
public:
    void BFS(vector<vector<char>>&grid,vector<vector<bool>>&visited,int r,int c,int n,int m){
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty()){
            auto front=q.front();q.pop();
            int x=front.first;
            int y=front.second;
            visited[x][y]=true;//don't use this here
            for(auto val:dir){
                int newX=x+val[0];
                int newY=y+val[1];
                if(newX<0||newY<0||newX>=n||newY>=m||visited[newX][newY]||grid[newX][newY]=='0'){
                    continue;
                }
                visited[newX][newY]=true;//think why this came here
                q.push({newX,newY});
            }
        } 
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    BFS(grid,visited,i,j,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};