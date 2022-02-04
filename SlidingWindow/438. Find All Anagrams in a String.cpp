class Solution {
public:
///with recursion
    void helper(string s,string p,int index,vector<int>&res){
        if(s.length()<p.length()){
            return;
        }
        if(s.length()==p.length()){
            sort(s.begin(),s.end());
            if(s==p){
                res.push_back(index);
            }
            return;
        }
        helper(s.substr(1),p,index+1,res);
        string firstK=s.substr(0,p.length());
        sort(firstK.begin(),firstK.end());
        if(firstK==p){
            res.push_back(index);
        }
        return;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
       // helper(s,p,0,res); with recursion
       sort(p.begin(),p.end());
       vector<int>wordS(26,0);
       vector<int>wordP(26,0);
       int n=s.length();
       int m=p.length();
       if(n<m){
           return res;
       }
       for(int i=0;i<m;i++){
          char ch=s[i];
          char ch2=p[i];
          int index=ch-'a';
          int index2=ch2-'a';
          wordS[index]++;
          wordP[index2]++;
       }
       if(wordS==wordP){
           res.push_back(0);
       }
       for(int i=1;(i+m)<=n;i++){
            int lastChar=s[i-1];
            int index=lastChar-'a';
            wordS[index]--;
            int newChar=s[i+m-1];
            int newIndex=newChar-'a';
            wordS[newIndex]++;
            if(wordS==wordP){
                res.push_back(i);
            }
       }
       return res;
    }
};