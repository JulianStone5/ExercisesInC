/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

/*
    1. The code is intended to print the contents of the array
    2. The warning means that the return statement will actually return the
       variables address, not the variable itself
    3. It prints the same address twice then gets a segmentation error because
       both functions are trying to use the same address
    4. Error still occurs
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();
    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
