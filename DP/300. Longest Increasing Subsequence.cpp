class Solution {
public:
   //using dp
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i])
               dp[i]=max(dp[i],1+dp[j]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    //using Binary-Search
    //https://www.youtube.com/watch?v=qW1O1a40-No&ab_channel=AryanMittal
    int lengthOfLIS(vector<int>&nums){
        int n=nums.size();
        vector<int>lis;//this is not the actual LIS,but contains element of LIS in sorted order
        lis.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>lis[lis.size()-1]){
               lis.push_back(nums[i]);
            }else{
              int index=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
              lis[index]=nums[i];
            }
        }
        return lis.size();
    }
};