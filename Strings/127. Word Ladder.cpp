class Solution {
public:
  
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s;
        for(auto x:wordList){
            s.insert(x);
        }
         if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
            return 0;
        queue<string>q;
        q.push(beginWord);
        int ans=0;
        while(q.size()!=0){
            ans++;
            int n=q.size();
            while(n--){
            string front=q.front();q.pop();
             for(int i=0;i<front.length();i++){
                 string temp=front;
                 for(char c='a';c<='z';c++){
                     temp[i]=c;
                     if(temp==front){
                         continue;
                     }else if(temp==endWord){
                         return ans+1;
                     }else if(s.find(temp)!=s.end()){
                         q.push(temp);
                         s.erase(temp);
                     }
                 }
             }
            }
        }
        return 0;
  
    }
};