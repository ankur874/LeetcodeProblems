class Solution {
public:
int helper(vector<int>&obstacles,int index,int lane,vector<vector<int>>&dp){

    if(index>=obstacles.size()-1){
        return 0;
    }
    if(dp[lane-1][index]!=-1){
        return dp[lane-1][index];
    }
    if(obstacles[index+1]!=lane){
        dp[lane-1][index]= helper(obstacles,index+1,lane,dp);
        return dp[lane-1][index];
    }
    if(lane==1){
        int o1=INT_MAX-1,o2=INT_MAX-1;
        if(obstacles[index]!=2){
            o1=1+helper(obstacles,index,2,dp);
        }
          if(obstacles[index]!=3){
            o2=1+helper(obstacles,index,3,dp);
        }
        dp[lane-1][index]= min(o1,o2);
        return dp[lane-1][index];
    }
     else  if(lane==2){
          int o1=INT_MAX-1,o2=INT_MAX-1;
        if(obstacles[index]!=1){
            o1=1+helper(obstacles,index,1,dp);
        }
          if(obstacles[index]!=3){
            o2=1+helper(obstacles,index,3,dp);
        }
        dp[lane-1][index]= min(o1,o2);
         return dp[lane-1][index];
    }
     else  if(lane==3){
       
          int o1=INT_MAX-1,o2=INT_MAX-1;
        if(obstacles[index]!=1){
            o1=1+helper(obstacles,index,1,dp);
        }
          if(obstacles[index]!=2){
            o2=1+helper(obstacles,index,2,dp);
        }
        dp[lane-1][index]= min(o1,o2);
         return dp[lane-1][index];
    }
    return -1;
    // return 0;
}
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>>dp(3,vector<int>(obstacles.size(),-1));
        return helper(obstacles,0,2,dp);
    }
};