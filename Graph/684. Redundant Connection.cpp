class Solution {
public:
    ///in brute force this does not get accepted
    bool dfs(vector<vector<int>>graph,int sv,int ev,vector<bool>visited){
         if(sv==ev){
             return true;
         }
        visited[sv]=true;
        bool ans=false;
         for(int i=0;i<graph.size();i++){
             if(graph[sv][i]==1&&!visited[i]){
                 ans= ans|dfs(graph,i,ev,visited);
             }
         }
         return ans;
    }
    ///in brute force bfs got accepted
    bool bfs(vector<vector<int>>graph,int sv,int ev,vector<bool>visited){
        queue<int>q;
        q.push(sv);
        while(!q.empty()){
            int front=q.front();q.pop();
            if(front==ev){
                return true;
            }
            visited[front]=true;
            for(int i=0;i<graph.size();i++){
                if(graph[front][i]==1&&!visited[i]){
                    q.push(i);
                }
            }
        }
        return false;
    }
    //brute force solution
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
       vector<vector<int>>graph(n,vector<int>(n,0));
       for(auto val:edges){
           graph[val[0]-1][val[1]-1]=1;
           graph[val[1]-1][val[0]-1]=1;
       }
       for(int i=n-1;i>=0;i--){
           int v1=edges[i][0]-1;
           int v2=edges[i][1]-1;
           graph[v1][v2]=0;
           graph[v2][v1]=0;
           vector<bool>visited(n,false);
           if(bfs(graph,v1,v2,visited)){
               return {v1+1,v2+1};
           }
           graph[v1][v2]=1;
           graph[v2][v1]=1;
       }
       return {-1,-1};
    }
};
///////////union find solution very tricky
// class Solution {
// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         vector<int> p(2000, 0);
//         for(int i = 0; i < p.size(); i++ )
//             p[i] = i;
        
//         vector<int> res;
//         for(auto v : edges ){
//             int n1 = v[0], n2 = v[1];
//             while(n1 != p[n1]) n1 = p[n1];
//             while(n2 != p[n2]) n2 = p[n2];
//             if( n1 == n2 )
//                 res = v;
//             else
//                 p[n1] = n2;
//         }
//         return res;
//     }
// };