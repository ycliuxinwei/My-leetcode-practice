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
		cout << p->val << " -> ";
		p = p->next;
	}
	cout << "end" << endl;
}

/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*/
void deleteNode(ListNode* node) {
	if(node!=NULL) {
		ListNode* tmp = node->next->next;
		node->next->next = tmp->next;
		delete tmp;
	}
}
int main() {
//	ListNode* p;
	ListNode *p = new ListNode(1);
	p->next = new ListNode(2);
	p->next->next = new ListNode(3);
	p->next->next->next = new ListNode(4);
	printListNode(p);
	
	deleteNode(p);
	printListNode(p);
	
	deleteListNode(p);
	
	return 0;
}