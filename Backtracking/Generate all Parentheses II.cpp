void solve(vector<string>&res,string temp,int n,int index,int o,int c){
    if(index>=2*n){
         res.push_back(temp);
         return;
    }
    if(o==c){
        temp.push_back('(');
        solve(res,temp,n,index+1,o+1,c);
        return;
    }
    if(o>=n){
        temp.push_back(')');
        solve(res,temp,n,index+1,o,c+1);
        return;
    }
    temp.push_back('(');
    solve(res,temp,n,index+1,o+1,c);
    temp.pop_back();
    temp.push_back(')');
    solve(res,temp,n,index+1,o,c+1);
}

vector<string> Solution::generateParenthesis(int n) {
    vector<string>res;
    string temp;
    solve(res,temp,n,0,0,0);
    return res;
}
