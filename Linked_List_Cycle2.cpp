
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;

        while (fastPointer && fastPointer->next){
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;

            if (fastPointer == slowPointer){
                ListNode* enterPointer = head;

                while (enterPointer != slowPointer){
                    enterPointer = enterPointer->next;
                    slowPointer = slowPointer->next;
                }
                return enterPointer;
            }
        }
        return nullptr;
    }
};