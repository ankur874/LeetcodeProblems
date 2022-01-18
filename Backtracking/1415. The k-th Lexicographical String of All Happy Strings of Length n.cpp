class Solution {
public:
    void helper(int n,int k,vector<string>&res,string formed,char noToBeTaken,vector<char>set){
        if(formed.length()==n){
            res.push_back(formed);
            return;
        }
        for(int i=0;i<set.size();i++){
            if(set[i]!=noToBeTaken){
                formed+=(set[i]);
                helper(n,k,res,formed,set[i],set);
                formed.pop_back();
            }
        }
        return;
    }
    string getHappyString(int n, int k) {
        vector<string>res;
        vector<char>set;
        set.push_back('a');
        set.push_back('b');
        set.push_back('c');
        string toBeFormed;
        char toBeIgnored;
        helper(n,k,res,toBeFormed,toBeIgnored,set);
        if(res.size()<k){
            return "";
        }
        return res[k-1];
    }
};