class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>temp,vector<int>nums,int k,int index,int n){
          if(k==0&&n==0){
              res.push_back(temp);
              return;
          }
        
        for(int i=index;i<nums.size();i++){
             temp.push_back(nums[i]);
             helper(res,temp,nums,k-1,i+1,n-nums[i]);
             temp.pop_back();
        }
       return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        vector<vector<int>>res;
        vector<int>temp;
        helper(res,temp,nums,k,0,n);
        return res;
    }
};