#include <stdio.h>
#include <stdlib.h>

/* Converts a card label to a number value assuming it is a legal card.
   Otherwise, assigns value to 0.

   card: string representing the card label
*/
int valAssign(char * card) {
  int val = 0;
  switch(card[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    default:
      val = atoi(card);
  }
  return val;
}

/* Takes a card value and returns the amount it will change the count.

   val: value of the card that is to change the count value
*/
int changeCount(int val) {
  if((val > 2) && (val < 7)) {
    return 1;
  } else if(val == 10) {
    return -1;
  }
  return 0;
}

/* Executes the card counting algorithm as long as the user wants. If the
   user inputs an "illegal" card, they will be notified. Otherwise, the
   count value will change until the user inputs "X".
*/
int main() {
  int count = 0;
  int val, change;
  char card_name[3];
  while(card_name[0] != 'X') {
    puts("Enter the card name: ");
    scanf("%2s", card_name);
    if(card_name[0] == 'X') {continue;}
    val = valAssign(card_name);
    change = changeCount(val);
    if((val < 1) || (val > 10)) {
      puts("I don't understand that value!");
      continue;
    }
    count = count + change;
    printf("Current count: %i\n", count);
  }
  return 0;
}
