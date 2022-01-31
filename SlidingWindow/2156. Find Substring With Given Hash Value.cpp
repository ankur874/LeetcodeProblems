class Solution {
public:
    // int findHash(string s,int p,int m,int k){
    //     int hash=0;
    //     for(int i=0;i<k;i++){
    //         int val=s[i]-'a'+1;
    //         hash=((hash%m)+(val%m*(int)pow(p,i)%m)%m)%m;
    //     }
    //     return hash%m;
    // }
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        // int n=s.length();
        // string firstString=s.substr(n-k);
        // int firstHash=findHash(firstString,power,modulo,k);
        // cout<<firstHash<<" ";
        // string res;
        // if(firstHash==hashValue){
        //     res=firstString;
        // }
        // for(int i=n-k-1;i>=0;i--){
        //     int newChar=s[i];
        //     int lastChar=s[i+k];
        //     int newCharHash=(newChar-'a'+1)*1;
        //     int lastCharHash=(lastChar-'a'+1)*pow(power,k-1);
        //     firstHash-=(lastCharHash%m);
        //     firstHash*=power;
        //     firstHash+=(newCharHash%m);
        //     if(firstHash==hashValue){
        //         res=s.substr(i,k);
        //     }
        // }
        // return res;
        int n=s.length();
        int index=0;
        int end=n-1;
        long hash=0;
        long pow=1;
        int c=k-1;
        while(c--){
            pow=(pow*power)%modulo;
        }
        for(int i=n-1;i>=0;i--){
            int val=s[i]-'a'+1;
            hash=(hash*power%modulo+val)%modulo;
            if(end-i+1==k){
                if(hash==hashValue){
                    index=i;
                }
                hash=(hash-(s[end]-'a'+1)%modulo*pow%modulo+modulo)%modulo;
                end--;
            }
        }
        // cout<<index;
        return s.substr(index,k);
       

    }
};