

#include <iostream>
#include <unordered_set>
#include "LinkedLists.h"

// ******************  SINGLE LINKED LIST WITH FUNCTIONS ******************************



/* Given a reference (pointer to pointer) to the head of a
list and an int, inserts a new node on the front of the list.*/
void push(SLNode** head_ref, int new_number)
{
	/* 1. allocate node */
	SLNode* new_node
		= (SLNode*)malloc(sizeof(struct SLNode));
	/* 2. put in the data */
	new_node->number = new_number;

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}

// Function to delete all nodes in the list
void deleteSLNodeAll(SLNode** head_ref)
{
	// If the list is empty, do nothing
	if ((*head_ref) == nullptr) {
		printf("\nList has no elements");
		return;
	}
	while ((*head_ref)) {
		// Store the current head in a temporary variable
		SLNode* temp = (*head_ref);

		// Update the head to the next node
		(*head_ref) = (*head_ref)->next;

		// Delete the old head node
		delete temp;
	}

	(*head_ref) = nullptr; //set the head to NULL
}

void deleteSLNodeAtPosition(SLNode** head_ref, int position)
{
	// If the list is empty, do nothing
	if ((*head_ref) == nullptr) {
		printf("List is empty. Cannot delete from a "
			"specific position.\n");

		return;
	}

	// If deleting the head node
	if (position == 0) {
		SLNode* temp = (*head_ref);
		(*head_ref) = (*head_ref)->next;
		delete temp;
		return;
	}

	// Traverse to the node just before the specified
	// position
	SLNode* current = (*head_ref);
	for (int i = 1;
		i < position && current->next != nullptr; ++i) {
		current = current->next;
	}
	//current is now at position before deletion.  THe node to be deleted is current->next
	
	// If position is beyond the end of the list, do nothing
	if (current->next == nullptr) {
		printf("Position is beyond the end of the list. "
			"Cannot delete.\n");
	}
	else {
		// Delete the node at the specified position
		SLNode* temp = current->next;  //node to be deleted is at current -> next.  Set the node in temp
		current->next = current->next->next; //point current next to the node after the to be deleted
		delete temp;  // delete the noede
	}
}

void deleteSLNodeAtBeginning(SLNode** head_ref)
{
	// If the list is empty, do nothing
	if ((*head_ref) == nullptr) {
		printf("List is empty.Cannot delete from the beginning.\n");
		return;
	}

	// Store the current head in a temporary variable
	SLNode* temp = (*head_ref);

	// Update the head to the next node
	(*head_ref) = (*head_ref)->next;

	// Delete the old head node
	delete temp;
}

// Function to delete a node at the end of the list
void deleteSLNodeAtEnd(SLNode** head_ref)
{
	// If the list is empty, do nothing
	if ((*head_ref) == nullptr) {
		printf("List is empty.Cannot delete from the end. \n");
		return;
	}

	// If there is only one node, delete it and set head to
	// null
	if ((*head_ref)->next == nullptr) {
		delete (*head_ref);
		(*head_ref) = nullptr;
		return;
	}

	// Traverse to the second last node
	SLNode* current = (*head_ref);
	while (current->next->next != nullptr) {
		current = current->next;
	}

	// Delete the last node
	delete current->next;
	current->next = nullptr;
}

void printNumbers(SLNode** head_ref) {
	SLNode* temp = (*head_ref);
	// If the list is empty, do nothing
	if ((*head_ref) == nullptr) {
		printf("\nList has no elements");
		return;
	}
	while (temp != nullptr) {
		printf("\n%d ", temp->number);
		//if(temp->next!=nullptr)
			//SLNode* nextnext = temp->next->next;

		temp = temp->next;

	}

}

// Function to find the length of the linked list
int findLength(SLNode** head_ref) {
	// Initialize a counter for the length
	int length = 0;

	// Start from the head of the list
	SLNode* current = (*head_ref);

	// Traverse the list and increment the length for each node
	while (current != nullptr) {
		length++;
		current = current -> next;
	}

	// Return the final length of the linked list
	return length;
}

// Function to search for a value in the Linked List
bool searchSLNodeList(SLNode** head_ref, int target) {

	SLNode* temp = (*head_ref);
	// Traverse the Linked List
	while (temp != nullptr) {
		// Check if the current node's data matches the target value
		if (temp->number == target) {
			return true;  // Value found
		}
		// Move to the next node
		temp = temp->next;
	}

	return false;  // Value not found
}

// BEGIN quick sort functions

SLNode* getTail(SLNode* cur)
{
	while (cur != NULL && cur->next != NULL) // while node not a null node
		cur = cur->next; // goto next and continue 
	return cur;  // return last node in list
}

// Partitions the list taking the last element as the pivot 
SLNode* partition( SLNode* head,  SLNode* end,
	 SLNode** newHead,
	 SLNode** newEnd)
{
	 SLNode* pivot = end;  // the pivot node starting at the end of the list
	 SLNode* prev = NULL;  // node used in partioning, used as the index
	 SLNode* cur = head;  // store the head of list in cur node.  
	 SLNode * tail = pivot; // set tail to the pivot node

	// During partition, both the head and end of the list 
	// might change which is updated in the newHead and 
	// newEnd variables 
	while (cur != pivot) {  // while the pivot hasnt been reached
		if (cur->number < pivot->number) {  // do the smaller than pivot test
			// First node that has a value less than the 
			// pivot - becomes the new head 
			if ((*newHead) == NULL)  //first encounter if newHead is null
				(*newHead) = cur; //move node into newHead

			prev = cur; // save index counter
			cur = cur->next; // goto next node
		}
		else // If cur node is greater than pivot 
		{
			// Move cur node to next of tail, and change 
			// tail.  Moves any node greater than pivot to the end of list, saving current
			//node in tmp which sets current to next node in the list.
			if (prev)
				prev->next = cur->next;
			SLNode* tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}

	// If the pivot data is the smallest element in the 
	// current list, pivot becomes the head 
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	// Update newEnd to the current last node 
	(*newEnd) = tail;

	// Return the pivot node 
	return pivot;
}

// here the sorting happens exclusive of the end node 
 SLNode* quickSortRecur( SLNode* head,
	 SLNode* end)
{
	// base condition 
	if (!head || head == end)
		return head;

	SLNode* newHead = NULL, * newEnd = NULL;

	// Partition the list, newHead and newEnd will be 
	// updated by the partition function 
	 SLNode* pivot
		= partition(head, end, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur 
	// for the left part. 
	if (newHead != pivot) {
		// Set the node before the pivot node as NULL so recursion stops at the left of the pivot
		 SLNode* tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;  // the node before pivot node sets to null.  We can now
		// quicksort recursivly to the left of the pivot

		// Recur for the list before pivot 
		newHead = quickSortRecur(newHead, tmp);

		// Change next of last node of the left half to 
		// pivot 
		tmp = getTail(newHead);
		tmp->next = pivot;
	}

	// Recur for the list after the pivot element 
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}

// The main function for quick sort. This is a wrapper over 
// recursive function quickSortRecur() 
void quickSort( SLNode** headRef)
{
	(*headRef)= quickSortRecur(*headRef, getTail(*headRef));
	return;
}

// END quick sort functions



// ******************  END  INGLE LINKED LIST WITH FUNCTIONS ******************************

// testing SLNode encapsulated in a "class" struct called SingleList -> LinkedLists.h
void SingleList::push(int new_number) //function in SingleList struct (class)
{
	/* 1. allocate node */
	SLNode* new_node
		= (SLNode*)malloc(sizeof(struct SLNode));
	/* 2. put in the data */
	new_node->number = new_number;

	/* 3. Make next of new node as head */
	new_node->next = list;

	/* 4. move the head to point to the new node */
	list = new_node;
}

void SingleList::printNumbers() {
	SLNode* temp = list;
	// If the list is empty, do nothing
	if (list == nullptr) {
		printf("\nList has no elements");
		return;
	}
	while (temp != nullptr) {
		printf("\n%d ", temp->number);
			temp = temp->next;

	}

}