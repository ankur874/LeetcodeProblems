int Solution::nTriang(vector<int> &A) {
    int n=A.size(),ans=0,m=1e9+7;
    sort(A.begin(),A.end());
   for(int i=n-1;i>=2;i--){
          int l=0;
          int r=i-1;
          while(l<r){
              if(A[l]+A[r]>A[i]){
                  ans=(ans%m+(r-l))%m;
                  r--;//ponder why we did r-- //take eg 2,1,2,1,1
              }else{
                  l++;
              }
          }
   }
    return ans;
}