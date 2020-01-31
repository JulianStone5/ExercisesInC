#include <stdio.h>

/* Lines 17-18 seem to represent line 6 here

   After optimization, there are less lines in the assemply code

   After changing the print statement, the assembly code was once again
   shorter with optimization

   The optimized version seems to shorten the code by removing as much
   referencing to the "5" within x. There doesn't seem to be any reference
   to that "5", meaning less space is going to be used, which is good.
*/
int main() {
  int x = 5;
  int y = x + 1;
  printf("%d",y);
  return 0;
}
