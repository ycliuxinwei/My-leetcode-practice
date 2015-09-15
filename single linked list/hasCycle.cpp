/* Copyright 2015 Edmund Liu

Given a linked list, determine if it has a cycle in it.

Follow up: Can you solve it without using extra space?
*/

#include <set>
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

bool hasCycle1(ListNode *head) {
    set<ListNode*> s;
    set<ListNode*>::iterator it;
    while (head != NULL) {
        it = s.find(head);
        if (it != s.end()) return true;
        else s.insert(head);
        cout << head->val;
        head = head->next;
    }
    return false;
}

bool hasCycle2(ListNode *head) {
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        head = head->next;
        fast = fast->next->next;
        if (head == fast) return true;
    }
    return false;
}

int main() {
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(5);
    p->next->next->next->next->next = p->next;
    cout << hasCycle2(p);
    return 0;
}
