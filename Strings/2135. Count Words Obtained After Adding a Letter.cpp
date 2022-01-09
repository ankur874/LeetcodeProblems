class Solution {
public:
    int wordCount(vector<string>& s, vector<string>& t) {
         set<string>se;
          for(int i=0;i<s.size();i++){
              sort(s[i].begin(),s[i].end());
              se.insert(s[i]);
          }
        for(int i=0;i<t.size();i++){
              sort(t[i].begin(),t[i].end());
          }
        int count=0;
        for(int i=0;i<t.size();i++){
              string oldS=t[i];
            // if(oldS.length()!=1)
              for(int j=0;j<oldS.length();j++){
                    string newS;
                  newS=oldS.substr(0,j)+oldS.substr(j+1);
                  // cout<<newS<<" ";
                  if(se.find(newS)!=se.end()){
                  count++;
                      break;
            }
              }
            
          }
        return count;
    }
};