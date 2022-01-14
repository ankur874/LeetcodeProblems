int Solution::braces(string A) {
    stack<char>s;
    for(int i=0;i<A.size();i++){
        if(A[i]==')'){
            int oc=0;
            while(s.size()!=0&&s.top()!='('){
                if(s.top()=='+'||s.top()=='-'||s.top()=='*'||s.top()=='/'){
                    oc++;
                }
                s.pop();
            }
            s.pop();
         if(oc==0){
             return 1;
           }
            
        }else{
            s.push(A[i]);
        }
    }
    return 0;
}
