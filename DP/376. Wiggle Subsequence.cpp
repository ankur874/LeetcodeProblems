class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
       int po=1;
       int ne=1;
        for(int i=1;i<nums.size();i++){
             if(nums[i]>nums[i-1]){
                 po=ne+1;
             }else if(nums[i]<nums[i-1]){
                 ne=po+1;
             }
        }
        return max(ne,po);
    }
};