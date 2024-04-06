#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
using namespace std;

#include "Classes.h"
int People::NUMBER_OF_RECORDS = 0;
int User::objInstance = 0;

/*Function to swap the nodes */
Person* People :: swap(Person* ptr1, Person* ptr2)
{
	Person* tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return ptr2;
}

void People::sortNames(int count) {

        Person **h;
		int i, j, swapped;

		for (i = 0; i <= count; i++) {

			h = &PeopleList;
			swapped = 0;

			for (j = 0; j < count - i - 1; j++) {

				Person* p1 = *h;
				Person* p2 = p1->next;

				if (strcmp(p1->name , p2->name)>0) {

					/* update the link after swapping */
					*h = swap(p1, p2);
					swapped = 1;
				}

				h = &(*h)->next;
			}

			/* break if the loop ended without any swap */
			if (swapped == 0)
				break;
		}
	}

People::People() {

 PeopleList = nullptr; 
 srand(time(0)); // seed the rand for unique Id's


}

void People::addPerson(Person *p) {

	Person* temp = new Person;
	temp->age = p->age;
	// deep copy of name (pointer)
	temp->name = new char[strlen(p->name)+1];
	strcpy_s(temp->name, strlen(p->name)+1, p->name);
	
	temp->uniqueId = rand();

	 /* 3. Make next of new node as head */
	temp->next = PeopleList;

	/* 4. move the head to point to the new node */
	PeopleList = temp; // temp;
	People::NUMBER_OF_RECORDS++;
	printf("\n\nName: %s  Age: %d Unique: %d", PeopleList->name, PeopleList->age, PeopleList->uniqueId);
	
}
void People::addPerson(char* name, int age) {
	Person* temp = new Person;

	//Person* temp = (Person*)malloc(sizeof(Person));
	temp->uniqueId = rand();
	// deep copy of name (pointer)
	temp->name = new char[strlen(name) + 1];
	strcpy_s(temp->name, strlen(name) + 1,name);
	temp->age = age;  // p->age;

	/* 3. Make next of new node as head */
	temp->next = PeopleList;

	/* 4. move the head to point to the new node */
	PeopleList = temp; // temp;
	People::NUMBER_OF_RECORDS++;
	printf("\n\nName: %s  Age: %d Unique: %d", PeopleList->name, PeopleList->age, PeopleList->uniqueId);
}

int People::findPerson(char* name, int age) {

	
	
	if ((name != nullptr) && (age != -1)) {
		// search on name and age
		
	}
	else if (age == -1) {

		//search on name
	}
	else if (name == "") {

		// search on age
	}

	return (1);
	

	}

People::~People() {

	Person* temp;
	printf("\nDestructor People List"); 
	while (PeopleList) {
		temp = PeopleList;  //point temp to head of list
		PeopleList = PeopleList->next; //point head of list to the next node inn list
		delete temp;  //delete temp (head of list)
		People::NUMBER_OF_RECORDS--;

	}

 

}


void People::displayPeople()
{
	Person* temp = PeopleList;

	// Check for empty list. 
	if (PeopleList == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list. 
	while (temp != NULL) {
		cout <<temp->name << " "<<endl;
		temp = temp->next;
	}
}


void printInfo(Dyr* dyr) {
	cout << "Dyr: " << dyr->getType() << endl;
}

// We can also declare "Create" outside Base
// But it is more relevant to limit it's scope to Base
CBase* CBase::Create(int id) {
	// Just expand the if-else ladder, if new Derived class is created
	// User code need not be recompiled to create newly added class objects

	if (id == 1)
	{
		return new CDerived1;
	}
	else if (id == 2)
	{
		return new CDerived2;
	}
	else if (id == 3)
	{
		return new CDerived3;
	}
	else {
		throw Exception((char*)"Can not create user.  Invalid user ID");
	}
}


//void People::addPerson(Person p) {

	//Person* temp = new Person;
	//Person* temp = (Person*)malloc(sizeof(Person));
   // Person P;
	//strcpy_s(temp->name, strlen(p.name), p.name);
	//temp->age = p.age;
	
	/* 3. Make next of new node as head */
//	temp->next = PeopleList;

	/* 4. move the head to point to the new node */
 //   PeopleList = temp; // temp;
//}


//void SingleList::push(int new_number) //function in SingleList struct (class)
 //{
	/* 1. allocate node */
//	SLNode* new_node
	//	= (SLNode*)malloc(sizeof(struct SLNode));
	/* 2. put in the data */
//	new_node->number = new_number;

	/* 3. Make next of new node as head */
//	new_node->next = list;

	/* 4. move the head to point to the new node */
//	list = new_node;


