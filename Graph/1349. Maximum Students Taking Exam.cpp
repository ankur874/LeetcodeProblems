class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
       string s;
        for(auto s1:seats){
            for(char val:s1){
                s.push_back(val);
            }
        }
        int m=seats.size();
        int n=seats[0].size();
        return dfs(s,n,m);
    }
    int dfs(string s,int m,int n){
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[i*n+j]=='.'){
                    s[i*n+j]='x';
                    maxi=max(maxi,dfs(s,m,n));                  
                    if(j+1<n){
                        if(i<m-1 && s[(i+1)*n+j+1] == '.') s[(i+1)*n+j+1] = 'x';
                        if(s[i*n+j+1] == '.') s[i*n+j+1] = 'x';
                    }
                    if(j-1>=0){
                        if(i<m-1 && s[(i+1)*n+j-1] == '.') s[(i+1)*n+j-1]= 'x';
                        if(s[i*n+j-1] == '.') s[i*n+j-1] = 'x';
                    }
                    maxi=max(maxi,1+dfs(s,m,n));
                }
            }
        }
        return maxi;
    }
};