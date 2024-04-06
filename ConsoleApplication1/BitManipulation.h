#pragma once
#include <iostream>

void bin(unsigned n);// takes an unsigned number and test each bit for if it is on or off and prints
// 0 for off and 1 for on.
int setBit(int n, int k); // sets a bit to on and given position

// Function to clear the kth bit of n 
int clearBit(int n, int k);
// Function to toggle the kth bit of n 
int toggleBit(int n, int k);
int isPowerOfTwo(unsigned n); // check to se if number contains only 1 bit set
// Returns position of the only set bit in 'n' 
int findPosition(unsigned n);
unsigned int countSetBits(unsigned int n);  // returns number of bits on in an integer
bool is_BitSet(int n, int pos);  // checks to see if a bit is set to 1 at a given position
bool bitsSet(int bitset, int mask); // checks to see if bits in a bitmask exist in a bitset

// Macros to manipulate a flag (key_state).  Must send a flag (key_state) and the position to manipulate
#define SetFlag(key_state, position) (key_state|= 1 << position)
#define ClearFlag(key_state,position) (key_state &= ~(1 << position))
#define ToggleFlag(key_state,position) (key_state ^= 1 << position)
#define isBitSet(key_state,position) (key_state &  (1 << position))