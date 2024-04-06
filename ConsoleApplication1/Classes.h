#pragma once
#include <iostream>
#include <stdio.h> 
using namespace std;




class Person{
private:
	int uniqueId;
	int age;
	char* name;
	Person* next;
public:
	Person() : next(nullptr), name(nullptr){};
	Person(char* name, int age);

	char* getName() {
		return name;
	}
	void setName(char* newName) { 
		//need deep copy
		if (name) {  //if person object is in used and name allready set delete the name (created dynamically) so a new can be created dynamically
			delete name; name = nullptr;
		}

		name = new char[strlen(newName) + 1];
		strcpy_s(name, strlen(newName) + 1, newName);
		printf("\n\nPerson Struckt->Name: %s  Age: %d Unique: %d", name, age, uniqueId);
	}
	
	void setAge(int newAge) { age = newAge; }
	int getAge(char* person);
	~Person() { printf("\nDestructor Person. Deleting name"); delete name; };
	friend class People;

};

class People {

private:
	Person* PeopleList;
	Person*getTail(Person* cur); // return last node in list
	// Partitions the list taking the last element as the pivot 
	Person*partition(Person* head, Person* end, Person** newHead, Person** newEnd);
	// here the sorting happens exclusive of the end node 
	Person*quickSortRecur(Person* head, Person* end);
	Person* swap(Person* ptr1, Person* ptr2);
	static int   NUMBER_OF_RECORDS;
	
public:
	
	People();
	void addPerson(Person *p);
	void addPerson(char* name, int age);
	int getUniqueId(char* name, int age);// returns -1 if more than one person has the same name and age
	int findPerson(int UniqueId);
	int findPerson(char* name = nullptr, int age=-1);
	void quickSortByAge();
	void sortNames(int count);
	void deletePerson(char *name);
	int  findNumberOfPeople();
	Person *searchPeople(char *name);
	void displayPeople();
	int numberOfRecords() { return NUMBER_OF_RECORDS; }
	~People();
};


/****************************   INHERITANCE  *******************************************************/

// base class
class Animal {
private:
	string color;

protected:
	string type;
public:
	void eat() {
		cout << "I can eat!" << endl;
	}

	void sleep() {
		cout << "I can sleep!" << endl;
	}

	void setColor(string clr) {
		color = clr;
	}

	string getColor() {
		return color;
	}
};

// derived class
class Dog : public Animal {

public:
	void bark() {
		cout << "I can bark! Woof woof!!" << endl;
	}

	void setType(string tp) {
		type = tp;
	}

	void displayInfo(string c) {
		cout << "I am a " << type << endl;
		cout << "My color is " << c << endl;
	}
};

class Cat : public Animal {
public:
	void miau() {
		cout << "I can miau! Miau Miau!!" << endl;
	}

};

/*                                  Access Modes in C++ Inheritance
* 
In our previous tutorials, we have learned about C++ access specifiers such as public, private, and protected.
So far, we have used the public keyword in order to inherit a class from a previously-existing base class. However, we can also use the private and protected keywords to inherit classes. For example,

class Animal {
    // code
};

class Dog : private Animal {
    // code
};
class Cat : protected Animal {
    // code
};

The various ways we can derive classes are known as access modes. These access modes have the following effect:
public: If a derived class is declared in public mode, then the members of the base class are inherited by the derived class just as they are.
private: In this case, all the members of the base class become private members in the derived class.
protected: The public members of the base class become protected members in the derived class.
The private members of the base class are always private in the derived class.    */


/********************************* ND INHERITANCE ***************************************************/

/********************** Member Function Overriding in Inheritance ***********************************/

class Base {
public:
	void print() {
		cout << "Base Function" << endl;
	}
	virtual void PrintVirtual() {

		cout << "Base Virtual Function" << endl;
	}
	virtual ~Base(){ cout << "Destructing base\n"; }
};

class Derived : public Base {
public:
	void print() {
		cout << "Derived Function" << endl;
		cout << "From inside derived class calling base class: Base::print() : "; Base::print();
	}
	void PrintVirtual() override {
		cout << "Derived Virtual Function" << endl;
	}
	
	~Derived()  { cout << "Destructing derived \n"; }
	

};

/********************** END Member Function Overriding in Inheritance ***********************************/

// Virtual functions withinn classes to get correct info from derived classes 

class Dyr {
private:
	string type;

public:
	// constructor to initialize type
	Dyr() : type("Dyr") {}

	// declare virtual function
	virtual string getType() {
		return type;
	}
};

class Hund : public Dyr {
private:
	string type;

public:
	// constructor to initialize type
	Hund() : type("Hund") {}

	string getType() override {
		return type;
	}
};

class Katt : public Dyr {
private:
	string type;

public:
	// constructor to initialize type
	Katt() : type("Katt") {}

	string getType() override {
		return type;
	}
};

void printInfo(Dyr* dyr);

class Vbase {
public:
	void fun_1() { cout << "base-1\n"; }
	virtual void fun_2() { cout << "base-2\n"; }
	virtual void fun_3() { cout << "base-3\n"; }
	virtual void fun_4() { cout << "base-4\n"; }
};

class Vderived : public Vbase {
public:
	void fun_1() { cout << "derived-1\n"; }  // limited to this class.  fun_1() in base is not virtual
	void fun_2() override { cout << "derived-2\n"; }  // redifining fun_2() in base (it is virutal)
	void fun_4(int x) { cout << "derived-4\n"; }  // not the same as virtual fun_4() in base, so function limited to 
													// this derived class only
};

class A {  //testing default parameters and scope in main.
public:
	virtual void fun(int x=0) { cout << "\n A::fun() called "<<x; }
	virtual ~A() { cout << "Destructer A called\n"; }
};

class B : public A {
public:
	void fun(int x=10) override { cout << "\n B::fun() called "<<x; }
	~B()  { cout << "Destructer B called\n"; }
};

class C : public B {
public:
	void fun(int x=20) override { cout << "\n C::fun() called "<<x; }
	~C()  { cout << "Destructer C called\n"; }
};


//creating a virtual constructor using static method in base class.  Testing functionality

//// LIBRARY START
class CBase
{
public:

	// The "Virtual Constructor".  Returns a derived object of this class based on id of the derived object
	static CBase* Create(int id);  // static functions do not get created with new objects and there will only
	//be one copy of this function in memory at all times regardless of how many instances of class is made

	CBase() { cout << "Creating CBase" << endl; }
	// The "Virtual Copy Constructor"
	virtual CBase* Clone() = 0;

	 // Ensures to invoke actual object destructor
	virtual	~CBase() { }

	// An interface
	virtual void DisplayAction() = 0;
};

class CDerived1 : public CBase
{
public:
	CDerived1()
	{
		cout << "Derived1 created" << endl;
	}

	~CDerived1()
	{
		cout << "Derived1 destroyed" << endl;
	}

	void DisplayAction()
	{
		cout << "Action from Derived1" << endl;
	}

	CBase* Clone()
	{
		return new CDerived1(*this);
	}
};

class CDerived2 : public CBase
{
public:
	CDerived2()
	{
		cout << "Derived2 created" << endl;
	}

	~CDerived2()
	{
		cout << "Derived2 destroyed" << endl;
	}

	void DisplayAction()
	{
		cout << "Action from Derived2" << endl;
	}
	CBase* Clone()
	{
		return new CDerived2(*this);
	}
};

class CDerived3 : public CBase
{
public:
	CDerived3()
	{
		cout << "Derived3 created" << endl;
	}

	~CDerived3()
	{
		cout << "Derived3 destroyed" << endl;
	}

	void DisplayAction()
	{
		cout << "Action from Derived3" << endl;
	}

	CBase* Clone()
	{
		return new CDerived3(*this);
	}
};

//// LIBRARY END

//// UTILITY START
class User
{

private:
	CBase* pBase;  // this is the pBase pointer returning derived class based on id input
	User* next; // set up for a linked list if needed

public:
	static int objInstance; //obj counter
	

	User(int id) : pBase(nullptr), next(nullptr)
	{
		// Receives an object of Base hierarchy at runtime

		/*int input;

		cout << "Enter ID (1, 2 or 3): ";
		cin >> input;

		while ((input != 1) && (input != 2) && (input != 3))
		{
			cout << "Enter ID (1, 2 or 3 only): ";
			cin >> input;
		}
		*/
		// Get object from the "Virtual Constructor"
		pBase = CBase::Create(id);
		User::objInstance++; // increase instances 
	}

	~User()
	{
		if (pBase)
		{
			delete pBase;
			pBase = nullptr;
			//User::objInstance--;
		}
	}

	// Delegates to actual object
	void Action()
	{
		
		pBase->DisplayAction();  //displays the correct DisplayAction based on class created by user input
	}

};

class Users {
	User* UserList;
public:
	Users() : UserList(nullptr){}
};

//// UTILITY END

// Excemption class 
class Exception {
	char* Message;
public:
	Exception(char* message) {
		Message = message;
	}
	char* getMessage() {
		return Message;
	}
};