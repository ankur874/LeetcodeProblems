class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>m;
        for(int val:nums4){
            for(int val1:nums3){
                ++m[val+val1];
            }
        }
        int res=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
              res+=m[-1*(nums1[i]+nums2[j])];
            }
        }
        return res;
    }
};