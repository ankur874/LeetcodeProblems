class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int front=q.front();q.pop();
            if(visited[front]){
                continue;
            }
            visited[front]=true;
            for(int val:rooms[front]){
                 q.push(val);
            }
        }
        for(bool val:visited){
            if(!val)return false;
        }
        return true;

    }
};