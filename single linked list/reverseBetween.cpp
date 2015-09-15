/* Copyright 2015 Edmund Liu

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    cout << "NULL" << endl;
}

/*
-------------        -------------
| head   |  |------->| right  |  |-------> tmp
|        ---|        |        ---|
|           |        |           |
-------------        -------------
*/
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL || head->next == NULL || m==n) return head;
    int i = 1;
    ListNode* result = head;
    ListNode* pre = NULL;
    while (i < m-1) {
        head = head->next;
        i++;
    }
    if (m != 1) {
        pre = head;
        head = head->next;
    }
    ListNode* start = head;
    ListNode* right = head->next;
    ListNode* tmp;
    while (i != n-1) {
        tmp = right->next;
        right->next = head;
        head = right;
        right = tmp;
        i++;
    }
    if (pre) {
        start->next = tmp;
        pre->next = head;
        return result;
    }
    else {
        tmp = right->next;
        right->next = head;
        head = right;
        start->next = tmp;
        return head;
    }
}

int main() {
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL
    ListNode* head = new ListNode(1);
    ListNode* list1 = head;
    for (int i = 1; i < 10; i++) {
        list1->next = new ListNode(i+1);
        list1 = list1->next;
    }
    printListNode(head);
    
    // 1 -> 5 -> 4 -> 3 -> 2 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL
    ListNode* reverse = reverseBetween(head, 2, 5);
    /* 5 -> 4 -> 3 -> 2 -> 1 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL
    ListNode* reverse = reverseBetween(head, 1, 5); */
    printListNode(reverse);
    deletelistNode(reverse);
    return 0;
}
