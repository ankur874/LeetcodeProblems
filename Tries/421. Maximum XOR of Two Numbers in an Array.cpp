class Solution {
public:
    class trieNode{
        public:
            trieNode* left;
            trieNode* right;
    };
     void insert(vector<int>nums,trieNode* head){
                for(int val:nums){
                    trieNode*curr=head;
                  for(int i=31;i>=0;i--){
                      int bit=val&(1<<i);
                      if(bit==0){
                          if(!curr->left){
                              curr->left=new trieNode();
                          }
                          curr=curr->left;
                      }else{
                         if(!curr->right){
                            curr->right=new trieNode();
                         }
                         curr=curr->right;
                      }
                  }
                }
          }
          int maxXORi(int val,trieNode* head){
              trieNode* curr=head;
              int ans=0;
              for(int i=31;i>=0;i--){
                  int bit=val&(1<<i);
                  if(bit==0){
                      if(curr->right){
                          ans+=pow(2,i);
                          curr=curr->right;
                      }else{
                          curr=curr->left;
                      }
                  }else{
                      if(curr->left){
                          ans+=pow(2,i);
                          curr=curr->left;
                      }else{
                          curr=curr->right;
                      }
                  }
              }
              return ans;
          }
    int findMaximumXOR(vector<int>& nums) {
        trieNode* head=new trieNode();
        insert(nums,head);
        int maxXOR=INT_MIN;
        for(int i=0;i<nums.size();i++){
           maxXOR=max(maxXOR,maxXORi(nums[i],head));
        }
        return maxXOR;
    }
};