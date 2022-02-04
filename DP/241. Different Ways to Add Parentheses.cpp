class Solution {
public:
   vector<int>helper(string expression,unordered_map<string,vector<int>>&dpMap){
        if(expression.length()<=0){
           return {};
       }
       if(expression.length()==1){
           vector<int>temp;
           temp.push_back(expression[0]-'0');
           return temp;
       }
      if(dpMap.count(expression)>0){
          return dpMap[expression];
      }
        vector<int>ans;
        int count=0;
        for(int i=0;i<expression.length();i++){
            if(expression[i]=='+'){
                count++;
                vector<int>left,right;
                if(dpMap.count(substr(0,i))>0){
                   left=dpMap[substr(0,i)];
                }else
                 left=diffWaysToCompute(expression.substr(0,i));
                 if(dpMap.count(substr(0,i))>0){
                     right=dpMap[substr(0,i)];
                 }
                 vector<int>right=diffWaysToCompute(expression.substr(i+1));
                 for(int val:left){
                     for(int val2:right){
                         ans.push_back(val+val2);
                     }
                 }
            }else if(expression[i]=='-'){
                count++;
                 vector<int>left=diffWaysToCompute(expression.substr(0,i));
                 vector<int>right=diffWaysToCompute(expression.substr(i+1));
                 for(int val:left){
                     for(int val2:right){
                         ans.push_back(val-val2);
                     }
                 }
            }else if(expression[i]=='*'){
                count++;
                 vector<int>left=diffWaysToCompute(expression.substr(0,i));
                 vector<int>right=diffWaysToCompute(expression.substr(i+1));
                 for(int val:left){
                     for(int val2:right){
                         ans.push_back(val*val2);
                     }
                 }
            }else if(expression[i]=='/'){
                count++;
                 vector<int>left=diffWaysToCompute(expression.substr(0,i));
                 vector<int>right=diffWaysToCompute(expression.substr(i+1));
                 for(int val:left){
                     for(int val2:right){
                         ans.push_back(val/val2);
                     }
                 }
            }
        }
        if(count==0){
            int len=expression.length();
            int num=0;
            for(int i=0;i<len;i++){
                num+=((expression[i]-'0')*pow(10,len-i-1));
            }
            ans.push_back(num);
        }
        return ans;
   }
    vector<int> diffWaysToCompute(string expression) {
        
        unordered_map<string,vector<int>>dpMap;
        return helper(expression,dpMap);
    }
};