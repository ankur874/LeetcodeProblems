bool isPall(string s,int si,int ei){
    while(si<=ei){
        if(s[si]!=s[ei]){
            return false;
        }
        si++;
        ei--;
    }
    return true;
}

void helper(vector<vector<string>>&res,vector<string>temp,string A,int index){
   if(index>=A.length()){
       res.push_back(temp);
       return;
   }
   for(int i=index;i<A.length();i++){
       if(isPall(A,index,i)){
            temp.push_back(A.substr(index,i-index+1));
            helper(res,temp,A,i+1);
            temp.pop_back();
       }
   }
   return;
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>>res;
    vector<string>temp;
    helper(res,temp,A,0);
    return res;
}
