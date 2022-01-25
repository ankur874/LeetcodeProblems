
class Solution {
public:
    struct comp {
        bool operator()(pair<int,double>p1, pair<int,double>p2)
        {
           return p1.second < p2.second;
        }
   };
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
         vector<vector<pair<int,double>>>adj(n);
         int i=0;
         for(auto val:edges){
             adj[val[0]].push_back({val[1],succProb[i]});
             adj[val[1]].push_back({val[0],succProb[i++]});
         }
        priority_queue<pair<int,double>,vector<pair<int,double>>,comp>q;
        vector<double>distance(n,INT_MIN);
        vector<bool>visited(n,false);
        distance[start]=1;
        q.push({start,1});
        while(!q.empty()){
            auto front=q.top();q.pop();
            int vertex=front.first;
            visited[vertex]=true;
            double dist=front.second;
            for(auto val:adj[vertex]){
                 if(!visited[val.first]&&distance[val.first]<dist*val.second){
                     distance[val.first]=dist*val.second;
                     q.push({val.first,distance[val.first]});
        
                 }
            }
        }
        return distance[end]==INT_MIN?0.000:distance[end];
    }
};