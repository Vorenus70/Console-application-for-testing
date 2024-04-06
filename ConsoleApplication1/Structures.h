#pragma once

typedef struct sPerson {
	int age;
	char name[20];
} sPerson;

typedef struct child {
	int age = 0;
	char* name = (char*)"No Children";

	// testing use of structure functions.  NOTE: not allowed i C, but in C++
	char* getName() {
		if (name)
			return name;
		else
			return (char*)"Child does not exist";
	};
	int setName(char* newName) {
		name = newName;
		return (0);
	
	};
}child;

typedef struct ptrPerson{
	int age;
	char* name;
	child c[10];  
	child* child = c; //  just to test pointer arrays acces from structs in main...
	// functions.  NOTE: not allowed i C, but in C++
	char* getName() {
			return name;
	};
	int setName(char* newName) {
		name = newName;
		return (0);
	};

}ptrPerson;

/* THE FOLLOWING STRUCTURES ARE USED FOR SINGLE LINKED LIST IN LINKEDLISTS.CPP AND LINKEDLISTS.H */
typedef struct SLNode {
	int number;
	SLNode* next = nullptr;
}SLNode;

typedef struct SingleList {
	SLNode* list = nullptr;
	void push(int new_number);
	void printNumbers();

}SingleList;