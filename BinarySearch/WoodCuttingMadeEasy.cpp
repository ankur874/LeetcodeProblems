int Solution::solve(vector<int> &A, int B) {
    int si=0;
    int ei=*max_element(A.begin(),A.end());
    if(B==0)return A[A.size()-1];
    int res=0;
    while(si<=ei){
        int mid=(si+ei)/2;
        long int c=0;
        for(int i=0;i<A.size();i++){
            if(A[i]>mid){
                c+=(A[i]-mid);
            }
        }
        if(c==B)return mid;
        if(c>B){
             res=mid;
             //yha pe isliye mid mein daal diya kyoki , ab hum search krnge ki kya pta
             //hum or wood save kr skte ho cutter ko upr set krke (with our wood condition satisfied)
             //but uss chkr mein jab hum si=mid+1 krnge toh kya pta agle round mein wood kum aaye
             // toh case k liye humne jab bhi hume required wood se jyda wood mili humne store kra liye
             // kya pta aage na mile..mil gyi toh usko store kra lenge nhi toh end mein isko return kr denge
            si=mid+1;
        }else{
            ei=mid-1;
        }
    }
    // cout<<si<<" "<<ei;
    return res;
}