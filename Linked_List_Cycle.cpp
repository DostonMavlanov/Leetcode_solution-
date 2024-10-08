struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;

        while (fastPointer && fastPointer->next){
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;

            if (fastPointer == slowPointer){
                return true;
            }
        }
        return false;
    }
};