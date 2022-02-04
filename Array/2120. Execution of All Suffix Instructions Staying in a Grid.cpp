class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
           vector<int>res;
           for(int i=0;i<s.length();i++){
               res.push_back(solve(n,startPos[0],startPos[1],s,i));
           }
        return res;
    }
    int solve(int n,int r,int c,string s,int index){
        int ans=0;
        for(int i=index;i<s.length();i++){
            if(s[i]=='L'){
               c--;
            }else if(s[i]=='R'){
               c++;
            }else if(s[i]=='U'){
               r--;
            }else if(s[i]=='D'){
               r++;
            }
            if(r<0||c<0||r>=n||c>=n){
                return ans;
            }else{
                ans++;
            }
        }
        return ans;
    }
};