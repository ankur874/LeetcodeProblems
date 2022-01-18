class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>temp,vector<int>&A,int B,int index){
    if(B<0){
        return;
    }
    if(B==0){
      
        res.push_back(temp);
        return;
    }
    for(int i=index;i<A.size();i++){
        temp.push_back(A[i]);
        helper(res,temp,A,B-A[i],i);//ponder over i..whynot i+1
        temp.pop_back();
    }
    return;
  }
    vector<vector<int> >combinationSum(vector<int> &A, int B) {
    vector<vector<int>>res;
    vector<int>temp;
    helper(res,temp,A,B,0);
    return res;
   }
};