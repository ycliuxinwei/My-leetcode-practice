/* Copyright 2015 Edmund Liu

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// doubly linked list
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

// why run time error ???
ListNode* rotateRight1(ListNode* head, int k) {
    ListNode* tmp = head;
    if (head == NULL) return NULL;
    vector<ListNode*> a;
    while (tmp!=NULL) {
        a.push_back(tmp);
        tmp = tmp->next;
    }
    int n = a.size();
    ListNode* result = a[n-k];
    a[n-1]->next = a[0];
    a[n-k-1]->next = NULL;
    return result;
}

ListNode* rotateRight2(ListNode* head, int k) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* tmp1 = head;
    ListNode* tmp2 = head;
    int n = 1;
    while (tmp1->next != NULL) {
        tmp1 = tmp1->next;
        n++;
    }
    k %= n;
    for(int i = 1; i < n-k; i++)
        tmp2 = tmp2->next;
    tmp1->next = head;
    ListNode* result = tmp2->next;
    tmp2->next = NULL;
    return result;
}

int main() {
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    printListNode(a);
    ListNode* b = rotateRight2(a, 2);
    printListNode(b);
    return 0;
}
