class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>cm;
        for(int val:nums){
            cm[val]++;
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            int possibleK=(nums[i]-nums[0]);
           unordered_map<int,int>m=cm;
           for(auto it=m.begin();it!=m.end();it++){
               if(it->second>0){
                   int toBeFind=it->first+possibleK;
                   if(m[toBeFind]>0){
                       ans.push_back(toBeFind-(possibleK/2));
                       m[toBeFind]--;
                       m[it->first]--;
                   }else{
                       // cout<<"ffssd";
                       ans.clear();
                       break;
                   }
               }
           }
            if(ans.size()*2==nums.size()){
                return ans;
            }
        }
        return ans;
    }
};