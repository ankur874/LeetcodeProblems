class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        vector<long long>pre(arr.size(),0);
        vector<long long>suff(arr.size(),0);
        vector<long long>res(arr.size(),0);
        for(auto it=m.begin();it!=m.end();it++){
            vector<int>temp=it->second;
            for(int i=1;i<temp.size();i++){
                pre[temp[i]]=pre[temp[i-1]]+(long)i*temp[i]-(long)i*temp[i-1];
            }
        }
        for(auto it=m.begin();it!=m.end();it++){
            vector<int>temp=it->second;
            for(int i=temp.size()-2;i>=0;i--){
                suff[temp[i]]=suff[temp[i+1]]+(long)(temp.size()-i-1)*temp[i+1]-(long)(temp.size()-i-1)*temp[i];
            }
        }
        for(int i=0;i<arr.size();i++){
            res[i]=pre[i]+suff[i];
        }
        return res;
    }
};