/* Copyright 2015 Edmund Liu

Reverse a singly linked list.
*/

#include <iostream>
using namespace std;

// linked list
struct ListNode{
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(NULL) {}
};

// delete the linked list
void deletelistNode(ListNode* p) {
    while (p != NULL) {
        ListNode* temp = p->next;
        delete p;
        p = temp;
    }
}

// print the linked list
void printListNode(ListNode* p) {
    while (p != NULL) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "end" << endl;
}

/*
-------------        -------------
| head   |  |------->| right  |  |-------> tmp
|        ---|        |        ---|
|           |        |           |
-------------        -------------
*/
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* right, *tmp;
    right = head->next;
    head->next = NULL;
    while (right->next != NULL) {
        tmp = right->next;
        right->next = head;
        head = right;
        right = tmp;
    }
    right->next = head;
    return right;
}

int main() {
    ListNode* head = new ListNode(0);
    ListNode* list1 = head;
    for (int i = 0; i < 5; i++) {
        ListNode* newlist = new ListNode(i+1);
        list1->next = newlist;
        list1 = list1->next;
    }
    printListNode(head);
    ListNode* reverse = reverseList(head);
    printListNode(reverse);
    deletelistNode(reverse);
    return 0;
}
