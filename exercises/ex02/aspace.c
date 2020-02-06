/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

/*
  4. After adding the second malloc() call, the heap does grow
  5. After adding the function the stack does go down
  6. Seems to allocate a size of 32 no matter the value in malloc() when using a
     value of 32 or less
*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int func() {
  int v = 1;
  printf ("Address of v is %p\n", &v);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *q = malloc(128);
    void *r = malloc(9);
    void *t = malloc(9);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of func is %p\n", func);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("q points to %p\n", q);
    printf ("r points to %p\n", r);
    printf ("t points to %p\n", t);
    printf ("s points to %p\n", s);

    return 0;
}
