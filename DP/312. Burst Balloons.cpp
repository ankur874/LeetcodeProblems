class Solution {
public:
    //very imp. DP question
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        int dp[n][n];
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++){
                    int left= k==i?0:dp[i][k-1];
                    int right= k==j?0:dp[k+1][j];
                    // int val= (i==0?1:nums[i-1])*nums[k]*(j==n-1?1:nums[j+1]);
                    int val=nums[k];
                    if(i-1>=0){
                        val*=nums[i-1];
                    }
                    if(j+1<n){
                        val*=nums[j+1];
                    }
                    int total=left+right+val;
                    maxi=max(maxi,total);
                    
                }
                dp[i][j]=maxi;
            }
        }
        return dp[0][n-1];
    }
};