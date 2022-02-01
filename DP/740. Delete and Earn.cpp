class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>helper(maxi+1,0);
        for(int val:nums){
            helper[val]+=val;
        }
        vector<int>dp(maxi+1);
        dp[1]=helper[1];
        dp[0]=helper[0];
        for(int i=2;i<maxi+1;i++){
           dp[i]=max(dp[i-2]+helper[i],dp[i-1]);
        }
        return dp[dp.size()-1];
    }
};