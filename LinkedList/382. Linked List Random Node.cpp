
class Solution {
public:
    ListNode*temp;
    int size;
    Solution(ListNode* head) {
       temp=head;
       size=0;
       while(temp!=nullptr){
           size++;
            temp=temp->next;
       }
        temp=head;
    }
    int getRandom() {
        int x=rand()%size;
        ListNode*res=temp;
        while(x--){
            res=res->next;
        }
        return res->val;
    }
};
