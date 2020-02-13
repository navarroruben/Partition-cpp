// Ruben Navarro
// 02/13/2020
// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. (leetcode)

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode * next;
    ListNode (int x) : val(x), next(nullptr) {}
};

// displays list
void displayList(ListNode* head) {

    if (head == nullptr) {
        std::cout << "head is NULL\n";
        return;
    }
    std::cout << "[";
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr)
            std::cout << ", ";
        head = head->next;
    }
    std::cout << "]" << std::endl;
}

int main() {

    // variable to be used for comparisons
    int x = 3;

    // list construction
    ListNode * head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = nullptr;

    // secondary pointer for traversal
    ListNode * curr = head;
    // vector to hold pointers to listnode type
    std::vector<ListNode*> v;

    // returns 0 is head is NULL
    if (head == nullptr) {
        displayList(head);
        return 0;
    }

    // returns zero and displays list if list only contains a single node
    if (head != nullptr && head->next == nullptr) {
        displayList(head);
        return 0;
    }

    // walks through list and pushes each pointer that contains a value less than x to vector
    while (curr != nullptr) {
        if (curr->val < x) {
            v.push_back(curr);
        }
        curr = curr->next;
    }

    // resets pointer to start
    curr = head;

    // walks through list and pushes each pointer greater than or equal to x into vector
    while (curr != nullptr) {
        if (curr->val >= x) {
            v.push_back(curr);
        }
        curr = curr->next;
    }

    // assigns first pushed in value to head of list and resets secondary pointer with new pointer.
    head = v[0];
    curr = head;

    // walks through vector and constructs new list from pointers in vector
    for (int i = 1; i < v.size(); ++i) {
        curr->next = v[i];
        curr = curr->next;
    }

    // sets final node to point at null
    curr->next = nullptr;

    displayList(head);
    return 0;
}
