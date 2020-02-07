#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Generates an integer array of 10 values based on user inputs. If the user
   inputs a number longer than 5 digits, or an invalid input, they will be
   warned. If the array is filled, they will also be warned.

   returns a pointer to the first value in the array
*/
int* generateArray() {
  static int array[10];
  int index = 0;
  int flag = 0;
  char n[100];
  puts("Enter numbers:");
  while(flag != EOF) {
    flag = scanf("%s",n);
    if(flag == EOF) {continue;}
    if(index == 10) {
      printf("No more integers can be stored.\n");
    }
    else if(strlen(n) >= 5){
      printf("Invalid integer length.\n");
    }
    else if(atoi(n) == 0) {
      printf("Invalid integer input.\n");
    } else {
      array[index] = atoi(n);
      index++;
    }
  }
  return array;
}

/* Calculates the sum of values given by a user input. The user input is filtered
   using the generateArray() function above, meaning the same warning messages
   will appear here. Once calulated, the sum will be printed.
*/
int main() {
  int sum = 0;
  int *array;
  array = generateArray();
  for(int i = 0; i < 10; i++) {
    sum += *(array+i);
  }
  printf("Sum: %d\n", sum);
  return 0;
}
