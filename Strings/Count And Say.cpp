string Solution::countAndSay(int A) {
     A--;
     string ans;
     ans='1';
     while(A--){
         pair<char,int>p;
         p.first=ans[0];
         p.second=1;
         string res;
         for(int i=1;i<ans.length();i++){
             if(ans[i]==ans[i-1]){
                 p.second++;
             }else{
                res+=to_string(p.second)+(p.first);
                p.first=ans[i];
                p.second=1;
             }
         }
         res+=to_string(p.second)+(p.first);
        //  cout<<res;
         ans=res;
     }
     return ans;
}
