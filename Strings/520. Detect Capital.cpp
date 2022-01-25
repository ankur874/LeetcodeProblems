class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()==1){
            return true;
        }
        bool isFirstCap=(word[0]>=65&&word[0]<=90);
        bool isSecondCap=(word[1]>=65&&word[1]<=90);
        cout<<isFirstCap<<" "<<isSecondCap;
        if(!isFirstCap){
            for(char val:word.substr(1)){
                  if(val>=65&&val<=90){
                      return false;
                  }
            }
        }else{
            if(isSecondCap){
                for(char val:word.substr(2)){
                      if(val>=97&&val<=122){
                          return false;
                      }
                }
            }else{
                for(char val:word.substr(1)){
                  if(val>=65&&val<=90){
                      return false;
                  }
                } 
            }
        }
        return true;
    }
};