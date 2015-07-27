#include <stdio.h>
#include <stdlib.h>

struct node {
  int letter;        // ascii code
  int appearance;
  struct node *(next[30]); // pointing to the start of an array of all next letters
  int size;
};

typedef struct node treeNode;
