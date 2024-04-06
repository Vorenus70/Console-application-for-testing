#pragma once
#include "Structures.h"


// ******************  SINGLE LINKED LIST WITH FUNCTIONS HEADERS ******************************

/* Given a reference (pointer to pointer) to the head of a
list and an int, inserts a new node on the front of the list.*/
void push(SLNode** head_ref, int new_number);

// Function to delete all nodes in the list
void deleteSLNodeAll(SLNode** head_ref);

void deleteSLNodeAtBeginning(SLNode** head_ref);

void deleteSLNodeAtPosition(SLNode** head_ref, int position);

// Function to delete a node at the end of the list
void deleteSLNodeAtEnd(SLNode** head_ref);

void printNumbers(SLNode** head_ref);

// Function to find the length of the linked list
int findLength(SLNode** head_ref);

// Function to search for a number in the Linked List
bool searchSLNodeList(SLNode** head_ref, int target);

SLNode* getTail(SLNode* cur); // return last node in list

// Partitions the list taking the last element as the pivot 
SLNode* partition( SLNode* head,  SLNode* end,
	 SLNode** newHead,
	 SLNode** newEnd);

// here the sorting happens exclusive of the end node 
 SLNode* quickSortRecur( SLNode* head,
	 SLNode* end);

// The main function for quick sort. This is a wrapper over 
// recursive function quickSortRecur() 
void quickSort( SLNode** headRef);




// ******************  END  INGLE LINKED LIST WITH FUNCTIONS ******************************
