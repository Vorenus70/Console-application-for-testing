#pragma once
#include <iostream>

#define ONE   0x00000001
#define TWO   0x00000020
#define THREE  0X00000800
#define TABLES 3
#define ROW 3
#define COL 9
#define STRINGLENGHT COL
#define NUMBEROFSTRINGS 5
int printName(char* name);
int print3DArray(char (*array)[ROW][COL], char flags);
int print2D(char **array, int numberOfStrings);
int pass3d(char* a, int StringLength, int numElements); //passing pointer to first element and size(length in characters) of the element (elements in 3d array)
