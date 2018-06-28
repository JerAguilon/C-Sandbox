struct LinkedListNode {
    int data;
    LinkedListNode* next;
};

LinkedListNode* delete_node(
        LinkedListNode* head,
        int key) {
    if (head == nullptr) return head;

    LinkedListNode* prev = nullptr;
    LinkedListNode* curr = head;

    while (curr) {
        if (curr->data == key) {
            LinkedListNode* temp = curr;
            if (prev) {
                prev->next = curr->next;
            } else {
                LinkedListNode* temp = head;
                head = head->next;
            }
            delete temp;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}
