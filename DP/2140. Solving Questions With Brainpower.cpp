class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(questions.size(),-1);
        dp[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--){
            long long o1=dp[i+1];
            long long o2=questions[i][0];
            if(i+1+questions[i][1]<n){
                o2+=dp[i+1+questions[i][1]];
            }
            dp[i]=max(o1,o2);
        }
        return dp[0];
        
    }
};