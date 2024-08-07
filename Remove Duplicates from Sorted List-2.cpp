struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* predNode = dummyNode;
        ListNode* curr = head;

        while (curr){
            while (curr->next && curr->next->val == curr->val){
                curr = curr->next;
            }
            if (predNode->next == curr){
                predNode = curr;
            }else{
                predNode->next = curr->next;
            }
            curr = curr->next;
        }
        return dummyNode->next;
    }
};