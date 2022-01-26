class Solution {
public:
    class Edge{
        public:
        int src;
        int dest;
        int weight;
    };
    static bool compare(Edge e1,Edge e2){
        return e1.weight<e2.weight;
    }
    int findParent(vector<int>&parent,int src){
    if(parent[src]==src){
        return src;
    }
    return findParent(parent,parent[src]);
}
    void kruskal(vector<Edge>arr,vector<Edge>&output,int n){
        sort(arr.begin(),arr.end(),compare);
        int count=0;
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int ipIndex=0;
        int opIndex=0;
        while(count<n-1){
            int src=arr[ipIndex].src;
            int dest=arr[ipIndex].dest;
            int destParent=findParent(parent,dest);
            int srcParent=findParent(parent,src);
            if(destParent!=srcParent){
                output[opIndex++]=arr[ipIndex];
                count++;
                parent[destParent]=srcParent;
            }
            ipIndex++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<Edge>arr;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i==j)continue;
                Edge e;
                e.dest=j;
                e.src=i;
                e.weight=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                arr.push_back(e);
            }
        }
        vector<Edge>output(n-1);
        kruskal(arr,output,n);
        int ans=0;
        for(auto val:output){
           ans+=val.weight;
        }
        //  for(auto val:arr){
        //    cout<<val.weight<<" ";
        // }
        return ans;
    }
};