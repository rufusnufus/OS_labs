/*
 * Memory wasn't allocated for s pointer.
 * So, by allocating some memory we solved the problem.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
      char ** s;
      char foo[] = "Hello World";
      // allocate memory at least for one char *
      s = (char **) malloc(sizeof(char *));
      // allocate enough memory for foo in s
      *s = (char *) malloc(sizeof(foo));
      *s = foo;
      printf("s is %s\n", *s);
      s[0] = foo;
      printf("s[0] is %s\n",s[0]);
      return(0);
}

/*

--Output--
s is Hello World
s[0] is Hello World

*/