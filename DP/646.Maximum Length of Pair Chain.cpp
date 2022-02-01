class Solution {
public:
   static bool cmp(vector<int>v,vector<int>v1){
       return v[1]>v1[1];
   }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        // int dp[pairs.size()];
        vector<int>dp(pairs.size(),1);
        // memset(dp,1,sizeof(dp));
        for(int i=1;i<pairs.size();i++){
            for(int j=i-1;j>=0;j--){
                if(pairs[j][0]>pairs[i][1])
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};