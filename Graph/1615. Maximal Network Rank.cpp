class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n);
        for(vector<int> val:roads){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[2]);
        }
        vector<int>connections(n,0);
       for(int i=0;i<adj.size();i++){
           connections[i]=adj[i].size();
       }
       int ans=INT_MIN;
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
              int paths=connections[i]+connections[j];
              bool isFound=false;
              for(auto val:adj[i]){
                 if(val==j){
                     isFound=true;
                     break;
                 }
              }
              if(isFound){
                  paths--;
              }
              ans=max(ans,paths);
           }
       }
       return ans;
    }
};