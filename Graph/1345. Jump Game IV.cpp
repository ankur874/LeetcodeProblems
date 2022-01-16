class Solution {
public: 
    int helper(vector<int>&arr,int index,vector<bool>visited,vector<int>dp){
        if(index<0||index>=arr.size()){
            return INT_MAX-1;
        }
        if(visited[index]==true){
            return 0;
        }
        visited[index]=true;
        if(index==arr.size()-1){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
       int o1=1+helper(arr,index+1,visited,dp);
       int o2=1+helper(arr,index-1,visited,dp);
       int ans=INT_MAX-1;
        for(int i=0;i<arr.size();i++){
            if(i!=index&&arr[i]==arr[index]&&i!=(index-1)&&i!=(index+1)){
                ans=min(ans,1+helper(arr,i,visited,dp));
            }
        }
        ans= min(o1,min(o2,ans));
        dp[index]=ans;
        return ans;
    }
    //////////////BFS solution
    int helper(vector<int>&arr,vector<bool>visited){
        map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        queue<int>storeIndices;
        storeIndices.push(0);
        int endPoint=arr.size()-1;
        int ans=0;
        while(!storeIndices.empty()){
            int n=storeIndices.size();
            while(n--){
                int front=storeIndices.front();storeIndices.pop();
                visited[front]=true;
                if(front==endPoint){
                    return ans;
                }
                int o1=front-1;
                int o2=front+1;
                if(o1>=0&&o1<=endPoint&&!visited[o1]){
                    storeIndices.push(o1);
                    visited[o1]=true;
                }
                if(o2>=0&&o2<=endPoint&&!visited[o2]){
                    storeIndices.push(o2);
                    visited[o2]=true;
                }
                vector<int>equals=m[arr[front]];
                for(int i=0;i<equals.size();i++){
                    if(equals[i]!=front&&!visited[equals[i]]){
                        storeIndices.push(equals[i]);
                        visited[equals[i]]=true;
                    }
                }
                m.erase(arr[front]);
            }
            ans++;
        }
        return ans;
    }
    int minJumps(vector<int>& arr) {
        vector<bool>visited(arr.size(),false);
        vector<int>dp(arr.size(),-1);
        return helper(arr,visited);
    }
};