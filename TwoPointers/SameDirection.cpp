
#include <iostream>
class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int val = 0, ListNode* next = nullptr){
        this->val = val;
        this->next = next;
    }
};
ListNode* findMiddle(ListNode *head){
    ListNode *slow  = head;
    ListNode *fast = head;
    while(fast !=nullptr && fast->next != nullptr ){
        slow = slow->next;
        fast = fast->next->next;
    } 
    
    return slow;
}
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL\n";
}

// Helper function to create a linked list
ListNode* createList(std::initializer_list<int> values) {
    ListNode* dummy = new ListNode(); // Dummy node for easier list creation
    ListNode* current = dummy;

    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }

    return dummy->next; // Return actual head
}
int main() {
    ListNode* head = createList({1, 2, 3, 4, 5}); // Example: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    std::cout << "Original list: ";
    printList(head);

    ListNode* middle = findMiddle(head);
    std::cout << "Middle node value: " << middle->val << "\n";

    return 0;
}