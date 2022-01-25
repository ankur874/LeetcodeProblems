//watch jeeny lecture for bridge in a graph
class Solution {
public:
     vector<vector<int>>adj;
     vector<int>inTime;//mein kis time aaya 
       vector<int>low;//merese esa connection ko merse jaldi aaya ho
       int timer=0;
       vector<vector<int>>ans;
       vector<bool>visited;
    
   void dfs(int node,int parent){
       inTime[node]=low[node]=timer;
       timer++;
       visited[node]=true;
       for(auto adjacent:adj[node]){
           if(adjacent==parent)continue;
           if(!visited[adjacent]){
               dfs(adjacent,node);
                low[node]=min(low[node],low[adjacent]);
               if(inTime[node]<low[adjacent]){
                   cout<<"dfdf";
                   ans.push_back({node,adjacent});
               }
           }else{
               low[node]=min(low[node],inTime[adjacent]);
           }
       }
   }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        visited.resize(n,false);
        low.resize(n,0);
        inTime.resize(n,0);
        for(auto val:connections){
           adj[val[0]].push_back(val[1]);
           adj[val[1]].push_back(val[0]);
        }
      
       dfs(0,-1);
       return ans;
    }
};