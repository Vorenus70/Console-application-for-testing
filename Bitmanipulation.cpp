#include <iostream>

void bin(unsigned n) // takes an unsigned number and test each bit for if it is on or off and prints
// 0 for off and 1 for on.
{
    unsigned i;
    printf("BINARY REPRESENTATION : \n");
    printf("\n");
    for (i = 32; i > 0; i--) {
        if (i >= 11)
            printf("%d ", i - 1);
        else
            printf("%d  ", i - 1);
    }
    printf("POSITION\n");

    // set i to 2^31 (bit in 31t position).  Mask it with number (n).  Positive match is output 1, negative match is output 0.  
    // divide number (i) by 2 (exponentially by 2) setting the bit to next position (to the right).  Do same mask test
    // untill number is zero and exits loop
    for (i = 1 << 31; i > 0; i = i / 2) {
        (n & i) ? printf("1  ") : printf("0  ");

    }
    printf("BIT STATUS");
}



int setBit(int n, int k) // sets a bit to on and given position
{
    return (n | (1 << (k - 1)));
}

// Function to clear the kth bit of n 
int clearBit(int n, int k)
{
    return (n & (~(1 << k)));
}

// Function to toggle the kth bit of n 
int toggleBit(int n, int k)
{
    return (n ^ (1 << (k - 1)));
}

int isPowerOfTwo(unsigned n)
{
    return n && (!(n & (n - 1)));
}

// Returns position of the only set bit in 'n' 
int findPosition(unsigned n)
{
    if (!isPowerOfTwo(n))
        return -1;

    unsigned i = 1, pos = 1;

    // Iterate through bits of n till we find a set bit 
    // i&n will be non-zero only when 'i' and 'n' have a set bit 
    // at same position 
    while (!(i & n)) {
        // Unset current bit and set the next bit in 'i' 
        i = i << 1;

        // increment position 
        ++pos;
    }

    return pos;
}
unsigned int countSetBits(unsigned int n)  // returns number of bits on in an integer
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

bool isBitSet(int n, int pos) {  // checks to see if a bit is set to 1 at a given position
    return ((n & (1 << (pos - 1))) != 0);  //decrement pos, since counting starts at zero
}