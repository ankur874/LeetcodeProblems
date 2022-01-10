string Solution::longestCommonPrefix(vector<string> &A) {
    string ans=A[0];
    for(int i=1;i<A.size();i++){
        int p1=0,p2=0;
        string newAns;
        while(p1<ans.length()&&p2<A[i].length()){
            if(ans[p1]==A[i][p2]){
                newAns+=ans[p1];
            }
            else{
                break;
            }
              p1++;
        p2++;
        }
      
        ans=newAns;
    }
    return ans;
}
