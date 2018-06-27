struct LinkedListNode {
    public:
        LinkedListNode* next;
};

// Runtime: O(n), Space: O(n)
LinkedListNode* reverse_recursive(
        LinkedListNode* head) {
    if (head == nullptr || head->next==nullptr) return head;
    LinkedListNode* newHead = reverse_recursive(head->next);  
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

// Runtime: O(n), Space: O(1)
LinkedListNode* reverse_iterative(LinkedListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    LinkedListNode* newHead = head;
    LinkedListNode* curr = head->next;
    newHead->next = nullptr;
    while (curr != nullptr) {
        LinkedListNode* nextCurr = curr->next;
        curr->next = newHead;
        newHead = curr;
        curr = nextCurr;
    }
    return newHead;
}
