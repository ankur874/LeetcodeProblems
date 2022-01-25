class Solution {
public:
    struct comp{
        bool operator()(vector<int>v1,vector<int>v2){
            return v1[2]>v2[2];
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
        priority_queue<vector<int>,vector<vector<int>>,comp>q;
        vector<int>res(3,0);
        q.push(res);
        // vector<vector<bool>>visited(n,vector<bool>(m,false));
        vector<vector<int>>directions(n,vector<int>(m,INT_MAX));
        directions[0][0]=0;
          while(!q.empty()){
              vector<int> front=q.top();q.pop();
              int x=front[0];
              int y=front[1];
              // visited[x][y]=true;
              int vall=front[2];
              if(x==n-1&&y==m-1){
                  return vall;
              }
              for(auto val:dir){
                  int newX=x+val[0];
                  int newY=y+val[1];
                  if(newX<0||newY<0||newX>=n||newY>=m){
                      continue;
                  }
                  int newV=max(vall,abs(heights[x][y]-heights[newX][newY]));
                  if(directions[newX][newY]>newV){
                    directions[newX][newY]=newV;
                    vector<int>res={newX,newY,newV};
                    q.push(res);
                  }
              }
          }
        return directions[n-1][m-1];
    }
};