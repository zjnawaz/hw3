#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void helper(Node *&head, Node *&smaller, Node *&larger, int pivot) {
	if(head == nullptr){
		smaller = nullptr;
		larger = nullptr;
	}
	else{
		if(head->val <= pivot){
			smaller = head;
			return helper(head->next, smaller->next, larger, pivot);
		}
		else if(head->val > pivot){
			larger = head;
			return helper(head->next, smaller, larger->next, pivot);
		}
	}
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	Node *&dummy = head;
	helper(head, smaller, larger, pivot);
	std::cout << "SETTING dummy TO NULL: " << dummy->val << std::endl;

	dummy = nullptr;
}