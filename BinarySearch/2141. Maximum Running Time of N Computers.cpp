class Solution {
public:
    bool cCanRun(long long HP,int n,vector<int>&batteries){
        long long totalHP=n*HP;
        //this is a very important loop...smj k jaana hai
        for(int i=0;i<batteries.size();i++){
            totalHP-=min(HP,(long long)batteries[i]);
        }
        return totalHP<=0;
        
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long totalHP=0;
        for(int i=0;i<batteries.size();i++){
            totalHP+=batteries[i];
        }
        long long minHP=0;
        long long maxHP=totalHP/n;
        long long ans=0;
        while(minHP<=maxHP){
             long long midHP=(minHP+maxHP)/2;
            if(cCanRun(midHP,n,batteries)){
                ans=midHP;
                minHP=midHP+1;
            }else{
                maxHP=midHP-1;
            }
        }
        return ans;
    }
};