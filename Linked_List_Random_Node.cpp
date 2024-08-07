#include <random>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* head;

    Solution(ListNode* head) {
        this->head = head;    
    }
    
    int getRandom() {
        int scope = 0;
        int chosenValue = 0;

        ListNode* currentNode = head;
        while (currentNode != nullptr){
            scope += 1;
            int randomNumber = 1 + rand() % scope;
            if (randomNumber == scope){
                chosenValue = currentNode->val;
            }
            currentNode = currentNode->next;
        }
        return chosenValue;
    }
};
