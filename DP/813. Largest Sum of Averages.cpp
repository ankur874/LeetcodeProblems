class Solution {
public:
    double helper(vector<int>&nums,int k,int index,vector<vector<double>>&dp){
        if(k<=0){
            return 0;
        }
        if(dp[k][index]!=-1){
            return dp[k][index];
        }
        double res=0.0;
        double sum=0.0;
        for(int i=index;i<nums.size();i++){
            sum+=nums[i];
            if(k!=1||i==nums.size()-1){
                res=max(res,sum/(i-index+1)+helper(nums,k-1,i+1,dp));
            }
        }
        dp[k][index]= res;
        return res;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>>dp(k+1,vector<double>(nums.size()+1,-1.0));
        return helper(nums,k,0,dp);
    }
};