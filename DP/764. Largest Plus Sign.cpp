class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>mat(n,vector<int>(n,1));
        for(auto val:mines){
            mat[val[0]][val[1]]=0;
        }
        vector<vector<int>>le,ri,up,dow;
        le=ri=up=dow=mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=n-i-1;
                int y=n-j-1;
                if(i>0&&up[i][j]){
                    up[i][j]+=up[i-1][j];
                }
                if(j>0&&le[i][j]){
                    le[i][j]+=le[i][j-1];
                }
                if(x<n-1&&dow[x][y]){
                       dow[x][y]+=dow[x+1][y];
                }
                if(y<n-1&&ri[x][y]){
                    ri[x][y]+=ri[x][y+1];
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res=max(res,min(le[i][j],min(ri[i][j],min(up[i][j],dow[i][j]))));
            }
        }
        return res;

    }
};