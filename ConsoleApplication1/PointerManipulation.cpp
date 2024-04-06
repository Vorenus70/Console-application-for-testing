#include "PointerManipulation.h"



int printName(char* name) {


    // Test to print a 1d char array held in pointer pptrName one character at a time.  Looping through incrementing pointer 
   // to next address segment e.g next character 
    int c = 0;
    int l = strlen(name);

    if (l == 0) return(0); //if string lengt=zero return false

    while (c < strlen(name)) { //while not end of array
        printf("%c", *name); //print character at current position
        name++; // increment to next character. Means: pointer base size (char) += sizeofchar system char
    }
	return (1);


}

int print3DArray(char(*array)[ROW][COL], char flags) {

    // SAME AS ABOVE BUT WITH A LOOP LOOPING THROUGH EACH ROW AND COLUMN
    printf("\n");
    for (int cc = 0; cc < TABLES; cc++) {
        for (int ccc = 0; ccc < ROW; ccc++) {
            if ((cc == 1 && ccc == 0 || cc==2 && ccc==0))
                printf(": ");
            printf("%s ", *(array + cc) + ccc);

        }
    }

    // SAME AS ABOVE BUT WITH WITH A POINTER TO THE FIRST COLUMN AND THEN INCREMENTING POINTER THROUGH ROWS
    char(*pc)[COL] = *array; // decay the 3D array into a 2D array getting pointer to [0][0]
    printf("\n");
    for (int ccc = 0; ccc < COL; ccc++) {  // Loop through total number of strings in the array
        if ((ccc == 3) || ccc==6)printf(": ");
        printf("%s ", *pc++); // increment to next element in 2D array [0][0] to [0][1] -> [1][1]-> [2][1]
        // since all elements in an array follow each other linearly  in memory.  Its
       // incrementing allocated 9characters of a time

    }

    // test printing each character in each element in the 3D array 
    printf("\n");
    if (flags & ONE) {
    for (int cc = 0; cc < TABLES; cc++) {  // each table
        for (int ccc = 0; ccc < ROW; ccc++) {  // each column (string) in table
            int l = strlen(*(*(array + cc) + ccc)); // get lenght of string for character count to only print exact nr of character in string
            for (int cccc = 0; cccc < l; cccc++)  // each row (character) in column
                printf("%c ", *(*(*(array + cc) + ccc) + cccc));
            printf(" "); //print a space between strings
        }
    }
}
    return(1);
}



int print2D(char **array, int numberOfStrings){
    //test 2D pointer array with mulitple strings.  char* str[4]
        //char* str[4] = { (char*)"\nString",(char*)"Topics", (char*)"Hello", (char*)"World" }; // 2D string pointer initialised
    int c = 0;
    printf("\n");
    for (c = 0; c < numberOfStrings; c++) {  // number of strings in the array
        // variable to iterate over ith string
        int j = 0;
        // jth character of string str[i] can be
        // accessed from the location str[i]+j
        while (*(array[c] + j) != '\0') {  // print each character of a string til end of string
            printf("%c", *(array[c] + j));
            j++;
        }
        // space after printing the ith string
        printf(" ");
    }
    printf("\n");
    return (1);
}

//passing pointer to first element and size(length in characters) of the element (elements in 3d array)
int pass3d(char* a, int StringLength, int numElements) {
    printf("\n\nBegin pass3d(char*a, int StringLength, int numElements)\n\n");
   
    int cc = 0;
    for (int c = 0; c < numElements; c++) {
        printf("   %s ", a + cc);
        cc += StringLength;
        
    }
    printf("\n\nEnd pass3d(char*a, int StringLength, int numElements)\n\n ");
    return(1);
}