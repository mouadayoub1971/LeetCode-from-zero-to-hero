struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
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
      
        while (currentNode != nullptr) {
            scope += 1;
          
            int randomNumber = 1 + rand() % scope;
          
            if (randomNumber == scope) {
                chosenValue = currentNode->val;
            }
          
            currentNode = currentNode->next;
        }
      
        return chosenValue;
    }
};

ListNode* head = new ListNode(1);
head->next = new ListNode(2);
head->next->next = new ListNode(3);
Solution* solution = new Solution(head);
int randomValue = solution->getRandom();

