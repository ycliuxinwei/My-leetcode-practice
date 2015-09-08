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
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* root = new ListNode(0);
	ListNode* sum = root;
	int carry = 0, add =0, a1 = 0, a2 = 0;
	while(l1!=NULL || l2!=NULL) {
		if(l1==NULL) a1 = 0; else { a1 = l1->val; l1 = l1->next; }
		if(l2==NULL) a2 = 0; else { a2 = l2->val; l2 = l2->next; }
		add = (a1 + a2 + carry)%10;
		carry = (a1 + a2 + carry)/10;
		sum->val = add;
		if( (l1!=NULL||l2!=NULL) || carry>0)
			sum->next = new ListNode(carry);
		sum = sum->next;
	}
	return root;
}

int main() {
//	ListNode* p;
	ListNode *p = new ListNode(5);
	p->next = new ListNode(4);
	p->next->next = new ListNode(8);
	p->next->next->next = new ListNode(3);
	printListNode(p);
	
	ListNode *q = new ListNode(5);
	q->next = new ListNode(3);
	q->next->next = new ListNode(4);
	printListNode(q);
	
	ListNode* out = addTwoNumbers(p,q);
	printListNode(out);
	
	deleteListNode(p);
	deleteListNode(q);
	deleteListNode(out);
	
	return 0;
}