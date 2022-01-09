class Solution {
public:
    int minSwaps(vector<int>& nums) {
       int c1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                c1++;
            }
        }
        nums.insert(nums.end(),nums.begin(),nums.end());
        int co=0;
        for(int i=0;i<c1;i++){
            if(nums[i]==0){
                co++;
            }
        }
        int ans=co;
        for(int i=c1;i<nums.size();i++){
            if(nums[i]==0){
                co++;
            }
            if(nums[i-c1]==0){
                co--;
            }
            ans=min(ans,co);
        }
        return ans;
        
    }
};