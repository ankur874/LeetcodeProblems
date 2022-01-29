class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int mini=INT_MAX;
         int maxProfit=0;
         int day=0;
         for(int val:prices){
             if(val<mini){
                 mini=val;
             }
             maxProfit=max(maxProfit,prices[day++]-mini);
         }
         return maxProfit;
    }
};