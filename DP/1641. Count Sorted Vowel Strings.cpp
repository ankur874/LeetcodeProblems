class Solution {
public:
    int countVowelStrings(int n) {
        // int dp[5];
        vector<int>dp(5,1);
        // memset(dp,1,sizeof(dp));
        int sum=5;
        int ans=5;
        for(int i=2;i<=n;i++){
            int newSum=0;
            for(int j=0;j<5;j++){
                // dp[j]=swap(dp[j],sum);
                int temp=sum;
                sum=dp[j];
                dp[j]=temp;
                sum=dp[j]-sum;
                newSum+=dp[j];
            }
            sum=newSum;
            ans=newSum;
        }
        return ans;
        
    }
};