class Solution {
public:
    //with dp and memoization
    bool helper(vector<int>&nums,int index,vector<int>dp){
        if(index>=nums.size()-1){
            return true;
        }
        if(dp[index]!=-1)return dp[index];
        int maxJump=nums[index];
        bool ans=false;
        for(int i=1;i<=maxJump;i++){
            ans=ans||helper(nums,index+i,dp);
        }
        dp[index]=ans;
        return ans;
    }
    //its a sort of dp but with one variable only
    bool canJump(vector<int>& nums) {
        int lastTrue=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=(lastTrue-i)){
                lastTrue=i;
            }else{
                continue;
            }
        }
        return lastTrue==0;
    }
};