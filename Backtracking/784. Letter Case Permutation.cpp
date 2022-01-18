class Solution {
public:
    void helper(string s,int index,vector<string>& res){
        if(index>=s.length()){
            res.push_back(s);
            return;
        }
            if(isdigit(s[index])){  
                helper(s,index+1,res);
            }
            else{
                char ch=tolower(s[index]);
                s[index]=ch;
                helper(s,index+1,res);
                char ch1=toupper(s[index]);
                s[index]=ch1;
                helper(s,index+1,res);
            }
        
        return;
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        helper(s,0,res);
        return res;
    }
};