class Solution {
public:
    int unionWithRank(int *parent,int node){
        if(parent[node]==node){
            return node;
        }
        parent[node]=unionWithRank(parent,parent[node]);
        return parent[node];
    }
    int findParent(int *parent,int node){
        if(parent[node]==node){
            return node;
        }
        parent[node]=findParent(parent,parent[node]);
        return parent[node];
    }
    int largestComponentSize(vector<int>& nums) {
         int max=*max_element(nums.begin(),nums.end());
         int *parent=new int[max+1];
         for(int i=0;i<=max;i++){
             parent[i]=i;
         }
         for(auto val:nums){
             for(int i=2;i*i<=val;i++){//over this also
                 if(val%i==0){
                     
                   int nodeParent=findParent(parent,val);
                   int factorParent=findParent(parent,i);
                   int factorParent2=findParent(parent,val/i);//thing over this
                   parent[factorParent]=nodeParent;
                   parent[factorParent2]=nodeParent;
                 }
             }
         }
        vector<int>childParent(max+1,0);
         for(int val:nums){
             int parents=unionWithRank(parent,val);
             cout<<parents<<" ";
             childParent[parents]++;
         }
         return *max_element(childParent.begin(),childParent.end());
    }
};