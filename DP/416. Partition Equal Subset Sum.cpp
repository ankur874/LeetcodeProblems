class Solution {
public:
    bool helper(vector<int>&nums,int f,int s,int index,vector<vector<int>>&dp,int sum){
        
       if(index>=nums.size()){
           if(f==sum/2)return true;
           return false;
       }
       if(dp[index][f]!=-1){
           return dp[index][f];
       }
       bool o1=helper(nums,f+nums[index],s,index+1,dp,sum);
       bool o2=helper(nums,f,s+nums[index],index+1,dp,sum);
       dp[index][f]= o1||o2;
       return dp[index][f];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int val:nums){
            sum+=val;
        }
        if(sum%2!=0)return 0;
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        // vector<int>dp(nums.size(),vector<int>(sum+1,vector<int>(sum+1,-1)));
        return helper(nums,0,0,0,dp,sum);
    }
};