#include <iostream>
#include <windows.h>
#include <signal.h>
#include <stdio.h> 


#include "BitManipulation.h"
#include "PointerManipulation.h"
#include "Structures.h"
#include "LinkedLists.h"
#include "Classes.h"

void clear(int numberOfLines) {
    int c = 0;
    while (c < numberOfLines) {
        printf("\n");
        c++;
    }
}
/*void handle_sigint(int sig)
{
    printf("Caught signal for terminate %d\n", sig);
   
    if (sig==3)
       exit(0);
}*/

/* BIT TESTING AND MANIPULATION.  SEE COMMETED INT MAIN BELOW CURRENT */

/* POINTER(s) TESTING AND MANIPULATION.  */

int main()  //pointers testing and manipulation
{
    char nnname[8] = { 'R','I','C','H', 'A','R','D','\0' };  //1D character array.  Could also be nname[8]="RICHARD\0";

    char name[3][9] = { "RICHARD", "PETRA", "JENNIFER" };//2D character array
    char nname[4][9] = { "JENNY", "LISE", "AUD", "HANS" }; //2D character array

    //[TABLE][ROWS][COLS]
    char name3D[TABLES][ROW][COL] = { {"PALLMALL", "PETTERO", "LEVEL"} , {"ODDEN", "RICKMAN", "HEUER"} , {"HANSEN", "MOEN", "SPORSTOL"} }; //3D character array

    char(*pptrName); // character pointer 1D
    char(*ptrName)[9]; // 2D character pointer 
    char(*ptrName3D)[ROW][COL]; // 3D character pointer 

    char* strPtr = (char*)"Hello World"; // 1D string pointer initialised with Hello World
    char* str[NUMBEROFSTRINGS] = { (char*)"\nString",(char*)"Topics", (char*)"Hello", (char*)"World", (char*)"BYE" };// 2D string pointer initialised

    pptrName = nnname; // assigning  character array to pointer 1D
    ptrName = name;  // assigning 2D NAME array to 2pointer
    ptrName3D = name3D; // assigning 3D array to 3D pointer

    //structures and pointers
    ptrPerson Personn = { 54, (char*)"Richard Odden" };
    SLNode *singleList=nullptr;
    SingleList sList;  //test encaptulated functions in a struct (c++ class type logic)

    //class testing
    People listPeople;
    Users UserList;
   
 
  /*  signal(SIGINT, handle_sigint);
    while (1)
    {
        printf("hello world\n");
        Sleep(100);
    }
    */

    // just for fun. Set the title for window console 
    SetConsoleTitle(L"Richard's Console Pointer and Bits Appliction\0");
   wchar_t title[1024];
    GetConsoleTitle(title,1024);
    printf("%ls\n\n", title);

    printName(pptrName); // print string one character at a time. PointerManipulation.cpp
   

    // print names pointer to the array. Note incrementing pointer with 1 gets next memory location(element)in array. 
    // It takes byte size of first array element * itself.  Times 2 is two bytes size of first element and gets 2nd element
    // In character array notation the following would be: ptr[0], ptr[1], ptr[2]. THere is actually no need to dereference using 
    // * for character pointers but using the standard notation for all pointers to arrays. This array is [3][9]

    printf("\n%s %s %c\n", *ptrName, *(ptrName + 1), *(*(ptrName + 1) + 2)); //<-accessing a single character T in PETRA. Inner *accesses 1 element,
    // second * accesses characters in 1th element
    ptrName = nname; // point to second name array.  This array has one more element compared to previous. This has [4][9]
    printf("%s %s %s %s\n", *ptrName, *(ptrName + 1), *(ptrName + 2), ptrName + 3); // print new names with same pointer

    printf("%c\n", name[2][3]); // TEST: print a character of name in second pos in first none pointer character array

    //TEST replacing value in a pointer 2D array.  Copying a new value in postion [3] of array it points to.
    strcpy_s(*(ptrName + 3), "HALLELU"); // copy hallelu into postion 3
    // see result in pointer array and array it points to.  It's identical as it should be
    printf("%s %s\n", ptrName + 3, nname[3]);

    //Testing 3D pointer array.  Access elements of 3D array.  Accessing Whole strings at any given element and any given
    // character within a string of an element (second argument-RICKMAN).
    //                      // printf("%d\t", *(*(*(arr + i) + j) + k)); 
    //                       [0][0][]    character [1][1][4]        [1][2][] 
    //                                      M in RICKMAN         
    printf("\n%s %c %s\n", *ptrName3D, *(*(*(ptrName3D + 1) + 1) + 4), *(ptrName3D + 1) + 1);
    //char name3D[2][3][9] ={ {"PALLMALL", "PETTERO", "LEVEL"} , {"ODDEN", "RICKMAN", "HEUER"} }; //3D character array

 // Printing all elements in the 3D array.  Bigger arrays go in a loop.
 // 3d array ptrName3D              [0][0][]      [0][1][]        [0][2][]       [1][0][]          [1][1][]            [1][2][]
    printf("\n%s %s %s : %s %s %s\n", *ptrName3D, *(ptrName3D)+1, *(ptrName3D)+2, *(ptrName3D + 1), *(ptrName3D + 1) + 1, *(ptrName3D + 1) + 2);

    // SEE PointerManipulation.cpp
    print3DArray(ptrName3D, ONE|TWO|THREE); // pass a pointers to the whole array (all elements) [TABLES][ROW][COL]
    pass3d((char*)ptrName3D, STRINGLENGHT,COL); // pass as a pointer to the first element in 3D array [0][0][0]
    print2D(str, NUMBEROFSTRINGS);
    // END PointerManipulation.cpp
    
    
    //INTEGER POINTERS
    int arr[3][4] = {{10, 11, 12, 13}, {20, 21, 22, 23},{30, 31, 32, 33}};
    int(*pptr)[4] = arr;  // a 1D pointer to a 2D array with 4 elements in each row


    int b = 0; int n = 0;
    printf("\n");
     for ( b = 0; b < 3; b++) {
         for (n = 0; n < 4; n++) {
             printf("%d ", *(*(pptr+b) + n)); // use outer and inner loop for [b][n]
        }
        printf("\n");
     }
     printf("\n");
     
     // test with integer pointer assign the 2d array for printing entire array
     int(*row) = *pptr;  // decay the 2d array into a 1d array
     for (n = 0; n < (4*3); n++) {  // untill all elements in array (in this case nr elements pr table*rows)
         printf("%d ", *row++); // increase row pointer address by 1 at a time pointing to the next element in row
     }
     
       
    // can use both notations.  Gets the address of pointer
    printf("\n\n%p %p %p\n", pptr, pptr + 1, pptr + 2); 
    printf("%p %p %p\n", *pptr, *(pptr + 1), *(pptr + 2));

    //can use both notations.  Gets the data the pointer points to
    printf("%d %d %d\n", **pptr, *(*(pptr + 1) + 2), *(*(pptr + 2) + 3)); // 10, 22, 33
    printf("%d %d %d\n", pptr[0][0], pptr[1][2], pptr[2][3]);
   

    /* 1 */  //POINTER DECAY PROCESS
#define TABLESS  2
#define ROWS    5
#define COLS    2

/* 2 */

        /* 3 */
    int array[TABLESS][ROWS][COLS] = {
                                        {   {10, 20}, 
                                            {30, 40}, 
                                            {50, 60}, 
                                            {70, 80}, 
                                            {90, 100} 
                                        },
                                        {   {18, 21},   
                                            {3, 4},     
                                            {5, 6}, 
                                            {7, 81}, 
                                            {9, 11} }
    };
    /* pointer to the first "table" level - array is 3-d but decays into 2-d giving out int (*)[5][2] */
    /* name your variables meaningully */
    int(*table_ptr)[ROWS][COLS] = array;  /* try to club up declaration with initialization when you can */
    int* iiiii = (int*)array; // pointer to the first element only
    
    /* 4 */
    size_t i = 0, j = 0, k = 0;

    printf("\n"); //TEST to print out array from a single integer pointer
    for (i = 0; i < ROWS * (TABLESS+COLS); ++i)  
        printf("%d ", *iiiii++);

    printf("\n\n");  // pointer decay run throuht
    for (i = 0; i < TABLESS; ++i)
    {
        /* pointer to the second row level - *table_ptr is a 2-d array which decays into a 1-d array */
        int(*row_ptr)[COLS] = *table_ptr++;
        for (j = 0; j < ROWS; ++j)
        {
            /* pointer to the third col level - *row_ptr is a 1-d array which decays into a simple pointer */
            int* col_ptr = *row_ptr++;
            for (k = 0; k < COLS; ++k)
            {
                printf("(%lu, %lu, %lu): %u\n", (unsigned long)i, (unsigned long)j, (unsigned long)k, *col_ptr++);  /* dereference, get the value and move the pointer by one unit (int) */
            }
        }
    }

    //STRUCTURES: Structures.h  NOTE: using c++ structures.
    printf("\n\nName: %s ", Personn.getName());
    Personn.setName((char*)"Petra Rickman");
    printf("\nName: %s ", Personn.getName());
    printf("\n\nName: %s ", (*(Personn.child+0)).getName()); // child nr 1 in pointer array position 0
    (*(Personn.child+5)).setName((char*)"Brandon Rickman"); // child nr 5 set name
    printf("\nName: %s ",(*(Personn.child+5)).getName()); // child nr 5


    // Single linked list testing
    printf("\n");

    push(&singleList, 10);
    push(&singleList, 60);
    push(&singleList, 40);
    push(&singleList, 30);
    push(&singleList, 50);
    push(&singleList, 20);

    printf("\nPrinting elements in Single Linked List");
    printNumbers(&singleList);
    deleteSLNodeAtPosition(&singleList, 3);
    printNumbers(&singleList);
    printf("\nLenght of list is: %d", findLength(&singleList));
    (searchSLNodeList(&singleList, 60)) ? printf("\nFound") : printf("\nNot found");


    printf("\n\n");
    printf("Sorted List\n");
    quickSort(&singleList);
    printNumbers(&singleList);

    push(&singleList, 900);
    printf("\n\nNew list, not sorted\n");
    printNumbers(&singleList);


    deleteSLNodeAll(&singleList);

    printf("\n\nUsing List struct (c++ class logic.  Struct with funtions");
    sList.push(9);
    sList.push(343);
    sList.push(23);
    quickSort(&sList.list);
    sList.printNumbers();
    
    //using classes and linked list
    Person TPerson;
    TPerson.setAge(89);
    TPerson.setName((char*)"From Person struck added");
    TPerson.setName((char*)"New Name from struct added");
    listPeople.addPerson(&TPerson);

    listPeople.addPerson((char*)"Richard Odden", 54);
    listPeople.addPerson((char*)"Petra Odden", 54);
    listPeople.addPerson((char*)"Jennifer Odden", 54);
    listPeople.addPerson((char*)"Dagmar Odden", 54);
    listPeople.addPerson((char*)"Ivar Odden", 54);
    listPeople.addPerson((char*)"Jon Kåre Myrene", 54);
    listPeople.addPerson((char*)"Alexander Rickman", 54);
    listPeople.addPerson((char*)"Brandon Rickman", 54);
    listPeople.addPerson((char*)"Elizabeth Heuer", 54);
    listPeople.addPerson((char*)"Katerhrine Heuer", 54);
    

    printf("\nUnsorted\n");
    listPeople.displayPeople();
    listPeople.sortNames(listPeople.numberOfRecords());

    printf("\n\nSorted\n");
    listPeople.displayPeople();

    clear(20);


    /* testing classes and inheritance */
   
    // Create object of the Dog class
    Dog dog1;
    Cat cat1;
    dog1.eat();
    dog1.sleep();
    dog1.setColor("black");

    // Calling member of the derived class
    dog1.bark();
    dog1.setType("mammal");

    // Using getColor() of dog1 as argument
    // getColor() returns string data
    dog1.displayInfo(dog1.getColor()); 
    cat1.miau();
    /* end classes and inheritance */

    /* testing Member Function Overriding in Inheritance */
    clear(2);
    Derived derived1;
    Base baseclass;
    Base* ptr = &derived1;
    derived1.print();
    baseclass.print();
    derived1.Base::print(); // call baseclass function of print through class derived2
    // call function of Base class using ptr
    clear(2);
    ptr->print();//will call print of baseclass even if it points to derived class.  Need virtual functions.
    ptr->PrintVirtual(); // will call print of derrived class since PrintVirtual is virtual in base and overidden in derrived
    
    /* testing Virtual functions */
    clear(3);
    // all derived classes point to the base class Dyr
    Dyr* dyr = new Dyr();
    Dyr* hund = new Hund();
    Dyr* katt = new Katt();
    // printInfo is virutal in Dyr class and implemented in each derived class.  The correct information about
    // the animal will be displayes.  E.g animal, dog, cat...
    printInfo(dyr);
    printInfo(hund);
    printInfo(katt);

    delete dyr;
    delete hund;
    delete katt;

    /*   V-functions examples      */
    Vbase* p;
    Vderived obj1;
    p = &obj1;

    clear(3);
    // Early binding because fun1() is non-virtual
    // in base
    p->fun_1();

    // Late binding (RTP)
    p->fun_2();

    // Late binding (RTP)
    p->fun_3();

    // Late binding (RTP)
    p->fun_4();

    // Early binding but this function call is
    // illegal (produces error) because pointer
    // is of base type and function is of
    // derived class
    // p->fun_4(5);

    clear(3);
    // Testing default function parameters and scope of classes containing virtual functions
    // An object of class C
    C c;
    // A pointer of class B pointing
    // to memory location of c
    B* bb =&c;

    // this line prints "C::fun() called"
    bb->fun(20);  // class C fun() called,  x=20
    bb->fun();  // class C fun() called , x=10 (uses B class default since not sending a value to x in call to c fun()
    bb->A::fun(); //base class A fun() called  x=0 (a fun())
    c.B::fun(); // calling derived class B fun() from derived (from B) class C, none pointer,  x=10 (b fun())
    c.B::A::fun(); // calling base class A fun() from derived C class, none pointer, x=0 (a fun())
    clear(3);

    /* testing functionality of "virtual constructor" and derived classes created at run time with user input*/
    clear(2);
   
    // create the user from input.  THe user class sends this off to static function in CBase class creating
    // the correct derrived object.  User object contains a pointer to base cass CBase
    int validInput = 0, input = 0;
  
    cout << "\nEnter ID (1, 2 or 3). Press ESC to quit: ";
    while(!validInput){
         try {  // static function from CBase used in User class will throw an exception if no valid input is sent 
             while (!GetAsyncKeyState(VK_ESCAPE)) {  //using GetAsyncKeyState just to test the function usage
                 if ((GetAsyncKeyState(0x31) & 0x8000)) input = 1;  // number one is entered
                 else if (GetAsyncKeyState(0x32) & 0x8000) input = 2; // number two is entered
                 else if (GetAsyncKeyState(0x33) & 0x8000) input = 3; // number three is entered
                 else if (GetAsyncKeyState(VK_ESCAPE)) break;  // esc is pressed break out of the loop

                 if ((input >= 1) && (input <= 3)) {
                    
                     User* user = new User(input);
                     // Action required on any of Derived objects
                     user->Action();
                     cout  << User::objInstance<<endl;
                     delete user;
                     cout << "\nEnter ID (1, 2 or 3). Press ESC to quit: ";
                     Sleep(150);  // have to wait 15ms so GetAsyncKey clears.  Or else it will loop and produce
                     // the user multipy times before it clears.
                     input = 0; 
                     
                 }
             }
             validInput = 1;  // esc was pressed in innerlopp, break out if the outer loop by setting validInput to true.
        }
        catch (Exception x) {  // custom exception class in classes.h
            cout << x.getMessage();
            break;
        }
    }

    clear(2);
    return (0);
}


/* BIT TESTING AND MANIPULATION.  VOID MAIN BELOW */  

// SEE Bitmanipulation.h and Bitmanipulation.cpp for macros and functions

                                                            //(8 4 2 1)                                             29th bit set
/* #define key 0x20000000  //29th bit  hex value using ^2 pr nibble (2 0 0 0  0 0 0 0 etc) which will be in binary like 0 0 1 0 0 0 0 0 0 0 0 etc...
#define key2 0x00000020  //5th bit
#define ALT_KEY 1<<24 // setting 24th bit by shifting
#define CTRL_KEY 1<<23 
#define ONE 1<<0 
#define TWO 1024 //using int setting 10th bit using 2^11 (n^bittosett)

int KEY_STATE = 0;  // global keystate

int main()  // Bit testing and manipulation
{
    
    unsigned int count = 0;
    KEY_STATE = ALT_KEY | CTRL_KEY | TWO|key;  // set multiple bits using mask
    KEY_STATE |= ONE | key2;  // add additional bits using a mask
    KEY_STATE |= 0x80; // set a single bit using a mask of a hex number (2^ of 1, 2, 4 (2^4 gives last option 8, highest bit in nibble)
                       // pr nibble).  This turns on bit 7

    // TEST DIRECTLY USING MASK
    // KEY_STATE &= ~(CTRL_KEY); // ~key;  // clear a flag
    // KEY_STATE ^= key;  // toggle a flag

    // TEST USING MACROS with position to manipulate.  
    SetFlag(KEY_STATE, 17);
    KEY_STATE = toggleBit(KEY_STATE,29);
    ClearFlag(KEY_STATE, 0);
    
    int y = 25;
    double power = pow(2, y);
    bin(KEY_STATE);  // check if correct bits are set (function)
    count = countSetBits((unsigned int)KEY_STATE);  //  count the number of bits set (function)
    printf("\n\nBits Set : %d\n\n", count);

    //test states using mask
    if (KEY_STATE & ALT_KEY)
        printf("ALT KEY SELECTED\n");
    if (KEY_STATE & CTRL_KEY)
        printf("CTRL KEY SELECTED\n");
    if (bitsSet(KEY_STATE, ALT_KEY | CTRL_KEY | key))// test function to see if keys in a mask are all set (or not) in the key_state
            printf("BITS SET IN MASK    ALL    EXIST IN KEY_STATE\n");
    else
        printf("BITS SET IN MASK    DON'T    ALL EXIST IN KEY_STATE\n");

    short x = 10;
    //test isBitSet() macro and pow()
    printf("\nBit status nr %d: %s\n\nPow (2^%d) functions says: %.0f. A integer that has (only) the %dth bit sett \n\n", x, (isBitSet(KEY_STATE, x))?"ON":"OFF",y, power,y);
} */


