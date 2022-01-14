
///////logic using vector
string Solution::solve(string A) {
    vector<pair<char,int>>m;
    string res;
    for(int i=0;i<A.length();i++){
        bool isF=false;
        for(int j=0;j<m.size();j++){
            if(m[j].first==A[i]){
                isF=true;
                m[j].second++;
                break;
            }
        }
        if(!isF){
            m.push_back({A[i],1});
        }
        isF=false;
        for(int j=0;j<m.size();j++){    
            if(m[j].second==1){
                isF=true;
                res+=(m[j].first);
                break;
            }
        }
        if(!isF){
            res+=('#');
        }
    }
    return res;
}
////////////logic using queue&map
string Solution::solve(string A) {
    unordered_map<char, int> mp;
    queue<char> q;
    string ans;
    for (auto c : A)
    {
        mp[c]++;
        q.push(c);
        while (!q.empty() && mp[q.front()] > 1)   q.pop();
        if (!q.empty())                         ans.push_back(q.front());
        else                                    ans.push_back('#');
    }
    return ans;
}