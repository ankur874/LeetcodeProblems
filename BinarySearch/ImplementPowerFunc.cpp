int Solution::pow(int x, int n, int d) {
    if(d==0){
        return 1;
    }
    if(x==0){
        return 0;
    }
    long long int ans=1;
    long base=x;
    while(n>0){
        if(n%2==0){
           base=(base*base)%d;
           n/=2;
        }else{
            ans=(ans*base)%d;
            n--;
        }
    }
    if(ans<0){
        ans=(ans+d)%d;
    }
    return ans;
}
