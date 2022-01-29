class Solution {
public:
  //top down memoization approach
    // int helper(vector<int>&nums,int index,vector<int>&dp){
    //     if(index>=nums.size()){
    //         return 0;
    //     }
    //     if(dp[index]!=-1)return dp[index];
    //     int o1=nums[index]+helper(nums,index+2,dp);
    //     int o2=helper(nums,index+1,dp);
    //     dp[index]= max(o1,o2);
    //     return dp[index];
    // }
    //tabular approach
    int rob(vector<int>&nums){
        int n=nums.size();
        vector<int>dp(n);
        if(n==1){
            return nums[0];
        }
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
           dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
    // int rob(vector<int>& nums) {
    //     vector<int>dp(nums.size()+1,-1);
    //   return helper(nums,0,dp);
    // }
};