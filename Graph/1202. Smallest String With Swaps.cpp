class Solution {
public:
int findParent(vector<int>&parent,int node){
    if(node==parent[node]){
        return node;
    }
    parent[node]=findParent(parent,parent[node]);
    return parent[node];
}
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.length();
         vector<int>parent(n);
         for(int i=0;i<n;i++){
             parent[i]=i;
         }
         for(auto val:pairs){
             int firstParent=findParent(parent,val[0]);
             int secondParent=findParent(parent,val[1]);
             if(firstParent!=secondParent)
             parent[firstParent]=secondParent;
         }
         map<int,priority_queue <char, vector<char>, greater<char>>>m;
         for(int i=0;i<s.length();i++){
             int root=findParent(parent,i);
             m[root].push(s[i]);
         }
         string ans;
         for(int i=0;i<n;i++){
            int root=findParent(parent,i);
            ans+=m[root].top();
            m[root].pop();
         }
         return ans;
    }
};