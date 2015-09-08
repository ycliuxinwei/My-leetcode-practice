#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteListNode(ListNode* p) {
	while(p != NULL) {
		ListNode* temp = p->next;
		delete p;
		p = temp;
	}
}

void printListNode(ListNode* p) {
	while(p != NULL) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << "end" << endl;
}

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.
*/
ListNode* partition(ListNode* head, int x) {
	ListNode* a = new ListNode(-1);
	ListNode* b = new ListNode(-1);
	ListNode* tmp1 = a;
	ListNode* tmp2 = b;
  	while (head != NULL) {
		if (head->val >= x) {
			tmp1->next = new ListNode(head->val);
			tmp1 = tmp1->next;
		}
		else {
			tmp2->next = new ListNode(head->val);
			tmp2 = tmp2->next;
		}
		head = head->next;
	}
	tmp2->next = a->next;
	ListNode* c = b->next;
	delete a; delete b;
	return c;
}

int main() {
	
	ListNode *p = new ListNode(1);
	p->next = new ListNode(4);
	p->next->next = new ListNode(3);
	p->next->next->next = new ListNode(2);
	p->next->next->next->next = new ListNode(5);
	p->next->next->next->next->next = new ListNode(2);
	printListNode(p);
	
	ListNode* q = partition(p, 3);
	printListNode(q);
	
	deleteListNode(p);
	deleteListNode(q);
	
	return 0;
}