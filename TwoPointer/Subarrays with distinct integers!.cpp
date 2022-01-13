int h(vector<int>&A,int b){
    int n=A.size();
    if(b==0)return 0;
    vector<int>sub(400002,0);
    int diff=0;
    int total=0;
    int j=0;
    for(int i=0;i<n;i++){
        if(sub[A[i]]==0){
            sub[A[i]]++;
            diff++;
        }else{
            sub[A[i]]++;
        }
        if(diff<=b){
            total+=(i-j+1);
        }else{
            while(j<=i&&diff>b){
                sub[A[j]]--;
                if(sub[A[j]]==0){
                    diff--;
                }
                j++;
            }
            total+=(i-j+1);
        }
    }
    return total;
}


int Solution::solve(vector<int> &A, int B) {
    return h(A,B)-h(A,B-1);
}
