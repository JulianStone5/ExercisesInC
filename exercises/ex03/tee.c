#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
1) Implementing the options wasn't too difficult. There were many ways of this,
   which made things a lot easier. The hard part for me was implementing a
   continuous input loop for adding lines to the file. I couldn't figure out
   how to end the loop best until I thought of EOF. I would probably find a
   better way to combine the two loops if possible to save lines/space.
2) The main difference I see is error handling. They are accounting for a
   multitude of possible errors that I do not look for. If I had more time and
   understanding of said errors, I would try to implement that too.
*/

int main(int argc, char *argv[]) {
  char line[80];

  FILE *f;
  char ch;
  while((ch = getopt(argc,argv,"a:")) != EOF) {
    switch(ch) {
      case 'a':
        f = fopen(optarg,"w+");
        break;
      default:
        fprintf(stderr, "Unknown option\n");
        return 1;
    }
  }
  while(scanf("%s", line) != EOF) {
    fprintf(f, "%s\n", line);
  }
  printf("Done\n");
  fclose(f);
  return 0;
}
