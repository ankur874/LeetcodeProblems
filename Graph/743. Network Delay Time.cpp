class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
         for(auto val:times){
             adj[val[0]-1].push_back({val[1]-1,val[2]});
         }
        
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
         vector<int>distance(n,INT_MAX);
         distance[k-1]=0;
         q.push({k-1,0});
         while(!q.empty()){
            int size=q.size();
                auto front=q.top();q.pop();
                int vertex=front.first;
                int dist=front.second;
                for(int i=0;i<adj[vertex].size();i++){
                  if(distance[adj[vertex][i].first]>adj[vertex][i].second+dist){
                      distance[adj[vertex][i].first]=adj[vertex][i].second+dist;
                      q.push({adj[vertex][i].first,adj[vertex][i].second+dist});
                  }
               }
         }
         int ans=INT_MIN;
         for(auto val:distance){
           ans=max(ans,val);
         }
         return ans==INT_MAX?-1:ans;
    }
};