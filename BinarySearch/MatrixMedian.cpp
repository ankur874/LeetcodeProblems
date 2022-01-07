int Solution::findMedian(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int TE=n*m;
    int si=INT_MAX;
    int ei=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            si=min(si,A[i][j]);
            ei=max(ei,A[i][j]);
        }
    }
    // cout<<si<<" "<<ei<<" ";
    while(si<=ei){
        int mid=(si+ei)/2;
        int sm=0,gr=0,eq=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]==mid){
                      eq++;
                }else if(A[i][j]<mid){
                 sm++;
                }else{
                 gr++;
                }
            }
        }
           
            if(sm<=((n*m)/2)){
                
                si=mid+1;
            }else{
                ei=mid-1;
            }
        
    }
    return ei;
}
