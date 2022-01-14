vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int>s;
    s.push(A[0]);
    vector<int>res;
    res.push_back(-1);
    for(int i=1;i<A.size();i++){
        if(s.top()<A[i]){
            res.push_back(s.top());
            s.push(A[i]);
        }else{
            while(s.size()!=0&&s.top()>=A[i]){
                s.pop();
            }
            if(s.size()==0)
            res.push_back(-1);
            else
            res.push_back(s.top());
            s.push(A[i]);
        }
    }
    return res;
}
