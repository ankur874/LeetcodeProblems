int count(vector<int>A,int x)
{
    int cnt=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<=x)
            cnt++;
    }
    return cnt;
}
int Solution::kthsmallest(const vector<int> &A, int B) {
    int lo=*min_element(A.begin(),A.end());
    int hi=*max_element(A.begin(),A.end());
    int ans=0;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        int val=count(A,mid);
        if(val>=B)
            {
              ans=mid; //ponder over this ,now i know the ans
              hi=mid-1; 
            }
        else if(val<B)
        {
            lo=mid+1;
        }
    }
    return ans;
}
