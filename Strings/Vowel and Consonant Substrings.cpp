long long mod=1e9+7;
int helper(string A,int conso,int vow){
   if(A.length()<=1){
        return 0;
    }
    int newConso=0,newVowels=0;
    if(A[0]=='a'||A[0]=='e'||A[0]=='i'||A[0]=='o'||A[0]=='u'){
        newConso=conso;
        newVowels=vow-1;
    }else{
        newConso=conso-1;
        newVowels=vow;
    }
    // long int smallAns=helper(A.substr(1),newConso,newVowels);
     if(A[0]=='a'||A[0]=='e'||A[0]=='i'||A[0]=='o'||A[0]=='u'){
       smallAns=(smallAns%mod+newConso)%mod;
    }else{
       smallAns=(smallAns%mod+newVowels)%mod;
    }
    return smallAns%mod;
}
int Solution::solve(string A) {
    int vow=0;
    int conso=0;
   
    for(int i=0;i<A.length();i++){
 if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'){
       vow++;
    }
    }
    conso=A.length()-vow;
    long long int ans=0;
    for(int i=0;i<A.length();i++){
       if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'){
         ans=(ans%mod+conso)%mod;
         vow--;
       }else{
               ans=(ans%mod+vow)%mod;
         conso--;
       }
    }
    return ans;
}
