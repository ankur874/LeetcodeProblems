class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>temp,int index,vector<int>&candidates,int target){       
        if(target<0){
            return;
        }
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(index>=candidates.size()){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i!=index && candidates[i-1]==candidates[i])continue;
            temp.push_back(candidates[i]);
            helper(res,temp,i+1,candidates,target-candidates[i]);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        helper(res,temp,0,candidates,target);
        return res;
    }
};