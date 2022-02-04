class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int ans=0;
       
           for(int i=0;i<seats.size();i++){
            for(int j=0;j<seats[0].size();j++){
                if(seats[i][j]=='.'){
                     vector<vector<bool>>visited(seats.size(),vector<bool>(seats[0].size(),false));
                    ans=max(ans,dfs(i,j,seats,visited));
                    // cout<<ans<<" ";
                }
            }
        }
        return ans;
    }

    int dfs(int r,int c,vector<vector<char>>&seats,vector<vector<bool>>&visited){
        if(r<0||c<0||r>=seats.size()||c>=seats[0].size()||seats[r][c]=='#'||visited[r][c]){
            return INT_MIN;
        }
        
        visited[r][c]=true;
        int ans=0;
        for(int i=0;i<seats.size();i++){
            for(int j=0;j<seats[0].size();j++){
                if(seats[i][j]!='#'&&!visited[i][j]){
                           if(check(i,j,seats,visited)){
                               // if(i==0&&j==4){
                               //     cout<<check(i,j,seats,visited)<<" ";
                               // }
                            ans=max(ans,1+dfs(i,j,seats,visited));  
                }
                }
            }
        }
        return ans;
    }
    bool check(int i,int j,vector<vector<char>>&seats,vector<vector<bool>>&visited){
        if(j-1>=0){
             if(seats[i][j-1]=='.'&&visited[i][j-1]){
                 return false;
             }
        }
         if(j+1<seats[0].size()){
             if(seats[i][j+1]=='.'&&visited[i][j+1]){
                 return false;
             }
        }
         if(i-1>=0&&j-1>=0){
             if(seats[i-1][j-1]=='.'&&visited[i-1][j-1]){
                 return false;
             }
        }
         if(i-1>=0&&j+1<seats[0].size()){
             if(seats[i-1][j+1]=='.'&&visited[i-1][j+1]){
                 return false;
             }
        }
        return true;
    }
};