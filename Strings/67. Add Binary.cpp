class Solution {
public:
    string addBinary(string a, string b) {
       reverse(a.begin(),a.end());
       reverse(b.begin(),b.end());
        string ans;
        int i=0;
        int j=0;
        int carry=0;
        while(i<a.length()||j<b.length()){
            int x=0;
            int y=0;
            if(i<a.length()){
                x=a[i]-'0';
            }
            if(j<b.length()){
                y=b[j]-'0';
            }
            int res=x+y+carry;
            if(res==3){
                ans+='1';
                carry=1;
            }else if(res==2){
                ans+='0';
                carry=1;
            }else if(res==1){
                ans+='1';
                carry=0;
            }else{
                ans+='0';
                carry=0;
            }
                     i++;
                     j++;
        }
                     if(carry==1){
                         ans+='1';
                     }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};