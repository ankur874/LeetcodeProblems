///my thinking Solution
vector<vector<int>>helper(vector<int>&A,int index){
    if(index>=A.size()){
        vector<vector<int>>res;
        vector<int>oneD;
        res.push_back(oneD);
        return res;
    }
    vector<vector<int>>smallAns=helper(A,index+1);
    vector<vector<int>>finalAns=smallAns;
    for(int i=0;i<smallAns.size();i++){
        smallAns[i].push_back(A[index]);
        sort(smallAns[i].begin(),smallAns[i].end());
        finalAns.push_back(smallAns[i]);
    }
    sort(finalAns.begin(),finalAns.end());
    return finalAns;
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    return helper(A,0);
}
///proper backtrack Solution
// void subset(vector<int> &A,vector<vector<int>> &ans,vector<int> temp,int index)
// {
//     //insert 
//     ans.push_back(temp);
    
//     for(int i=index;i<A.size();i++)
//     {
//         temp.push_back(A[i]);
//         subset(A,ans,temp,i+1);
//         temp.pop_back();
//     }
//     return;
// }



// vector<vector<int> > Solution::subsets(vector<int> &A) {
//     vector<vector<int>> ans;
//     sort(A.begin(),A.end());
//     int index=0;
//     vector<int> temp;
//     subset(A,ans,temp,index);
//   return ans;
    
// }

