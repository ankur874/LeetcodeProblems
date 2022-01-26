class Solution {
public:
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node){
            return node;
        }
        parent[node]=findParent(parent,parent[node]);
        return parent[node];
    }

    int removeStones(vector<vector<int>>& stones) {
        int ans=0;
        vector<int>parent(stones.size(),0);
        for(int i=0;i<stones.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<stones.size();i++){
            for(int j=0;j<stones.size();j++){
                if(i==j)continue;
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                    int p1=findParent(parent,i);
                    int p2=findParent(parent,j);
                    if(p1!=p2){
                        parent[p1]=p2;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};