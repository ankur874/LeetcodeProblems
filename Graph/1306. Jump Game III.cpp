class Solution {
public:
    //its time complexity is very tricky
    //find it and ponder why
    bool canReach(vector<int>& arr, int start,vector<bool>&visited) {
        if(start<0||start>=arr.size()){
            return false;
        }
        if(visited[start]==true)return false;
        visited[start]=true;
        if(arr[start]==0){
            return true;
        }
        int o1=start+arr[start];
        int o2=start-arr[start];
        return (canReach(arr,o1,visited)||canReach(arr,o2,visited));
    }
    bool canReach(vector<int>&arr,int start){
        vector<bool>visited(arr.size(),false);
        return canReach(arr,start,visited);
    }
};