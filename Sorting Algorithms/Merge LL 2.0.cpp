struct Node {
    int data;
    Node* next;
};

// Function to merge two sorted lists
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = nullptr;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    }
    else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Main Merge Sort function
Node* mergeSort(Node* head) {
    // Base case: if list is empty or has one node
    if (!head || !head->next) return head;

    // 1. Split the list into two halves
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr; // Break the list into two parts

    // 2. Recursively sort both halves
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);

    // 3. Merge the sorted halves
    return merge(left, right);
}