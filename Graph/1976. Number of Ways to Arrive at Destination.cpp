class Solution {
public:
    struct comp {
    bool operator()(pair<long long,long long> p1, pair<long long,long long> p2)
    {
        
        return p1.second > p2.second;
    }
   };
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>>adj(n);
        for(auto val:roads){
             adj[val[1]].push_back({val[0],val[2]});
             adj[val[0]].push_back({val[1],val[2]});
         }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,comp>q;
        q.push({0,0});
        vector<long long>dist(n,LONG_MAX);
        dist[0]=0;
        long long MOD=1e9+7;
        vector<long long>dp(n);//dp[i] stores that to reach i , how many ways we have
        dp[0]=1;
         while(!q.empty()){
             auto top=q.top();q.pop();
             long long v1=top.first;//0
             long long weight=top.second;//0
             for(auto val:adj[v1]){
                 if(dist[val.first]>val.second+weight){
                     dist[val.first]=val.second+weight;
                     dp[val.first]=dp[v1];//very imp. line
                     q.push({val.first,dist[val.first]});
                 }else if(dist[val.first]==val.second+weight){//this condition is very imp.
                     dp[val.first]=(dp[val.first]+dp[v1])%MOD;//this also
                 }
             }
         }
         return (int)dp[n-1];
    }
};