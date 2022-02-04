class Solution {
public:
   static bool compare(pair<int,int>p1,pair<int,int>p2){
       if(p1.second==p2.second){
           return p1.first<p2.first;
       }
       return p1.second<p2.second;
   }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>arr;
        for(int i=0;i<ages.size();i++){
            arr.push_back({scores[i],ages[i]});
        }
        sort(arr.begin(),arr.end(),compare);
        vector<int>dp(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            dp[i]=arr[i].first;
        }
        // dp[0]=arr[0].first;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<i;j++){

                if(arr[j].first<=arr[i].first){
                    dp[i]=max(dp[i],dp[j]+arr[i].first);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
 
};