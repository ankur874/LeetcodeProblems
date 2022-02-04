class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         unordered_map<int,int>m;
         int res=0;
         int sum=0;
         for(int i=0;i<nums.size();i++){
             sum+=(nums[i]==0)?-1:1;
             auto it=m.find(sum);
             if(sum==0){
                 res=max(res,i+1);
             }
             else if(it==m.end()){
                 m[sum]=i;
             }else if(it!=m.end()){
                 res=max(res,i-it->second);
             }
         }
         return res;
    }
};