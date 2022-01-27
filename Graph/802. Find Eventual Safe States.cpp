class Solution {
public:  
    bool DFSTerminal(int node,vector<vector<int>>&graph,vector<bool>visited,vector<int>&dp){
         if(graph[node].size()==0){
             return true;
         }
         if(visited[node]){
             return false;
         }
         visited[node]=true;
        if(dp[node]!=-1){
            return dp[node];
        }
         for(int val:graph[node]){
            bool smallAns=DFSTerminal(val,graph,visited,dp);
            if(!smallAns){
                dp[node]=false;
                return false;
            }
         }
        dp[node]=true;
         return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>safeStates;
        vector<int>dp(graph.size(),-1);//we applied dp ponder over this..how dp is applied
        for(int i=0;i<graph.size();i++){
            bool isSafeState=true;
            for(int val:graph[i]){
                vector<bool>visited(graph.size(),false);
              if(!DFSTerminal(val,graph,visited,dp)){
                  dp[val]=0;
                  isSafeState=false;
                  break;
              }else{
                  dp[val]=1;
              }
            }
            if(isSafeState){
                dp[i]=1;
                safeStates.push_back(i);
            }
        }
        return safeStates;
    }
};