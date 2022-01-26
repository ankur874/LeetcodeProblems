class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        for(auto val:prerequisites){
            adj[val[1]].push_back(val[0]);
        }
        vector<int>inDegree(n,0);
        for(auto val1:adj){
           for(auto val:val1){
              inDegree[val]++;
           }
        }
        queue<int>q;
       for(int i=0;i<n;i++){
           if(inDegree[i]==0){
               q.push(i);
           }
       }
         for(int val:inDegree){
            cout<<val<<" ";
        }
        vector<int>res;
        while(!q.empty()){
            int front=q.front();q.pop();
            res.push_back(front);
            for(auto val:adj[front]){
               inDegree[val]--;
               if(inDegree[val]==0){
                   q.push(val);
               }
            }
        }
        return res.size()==n;
    }
};