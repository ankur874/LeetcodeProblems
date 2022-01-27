class Solution {
public:
    int dfs(int i,vector<vector<int>>& adj,vector<int>& ans,vector<int>& quiet){
        int curr=i;
        for(auto val:adj[curr]){
            if(ans[val]!=-1){
                if(quiet[ans[val]] < quiet[curr]){
                    curr=ans[val];
                }
            }
            else{
                int somePerson=dfs(val,adj,ans,quiet);
                if(quiet[somePerson] < quiet[curr]){
                    curr=somePerson;
                }
            } 
        }
        ans[i]=curr;
        return curr;
    }
    //try with topo sort also
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
         vector<vector<int>>adj(n);
         for(auto val:richer){
             adj[val[1]].push_back(val[0]);//ponder why 1->0 not 0->1
         }
        vector<int>ans(n,-1);
         for(int i=0;i<n;i++){
             if(ans[i]==-1)
            dfs(i,adj,ans,quiet);
        
         }
         return ans;
        
    }
};