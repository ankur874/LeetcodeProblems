class Solution {
public:
    void BFS(vector<vector<int>>&image,vector<vector<bool>>&visited,int n,int m,int sr,int sc,int newColor){
        queue<pair<int,int>>q;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        q.push(make_pair(sr,sc));
        while(!q.empty()){
            auto front=q.front();q.pop();
            int x=front.first;
            int y=front.second;
            cout<<x<<" "<<y<<" ";
            visited[x][y]=true;
            for(auto val:dir){
                int newX=x+val[0];
                int newY=y+val[1];
                if(newX<0||newY<0||newX>=n||newY>=m||visited[newX][newY]||image[newX][newY]!=image[x][y]){
                    continue;
                }
                q.push(make_pair(newX,newY));
            }
            image[x][y]=newColor;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        BFS(image,visited,n,m,sr,sc,newColor);
        return image;
    }
};