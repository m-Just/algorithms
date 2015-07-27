#include <trieTree.h>

int readVocabulary() {
  /* Construct dictionary */
  
  // dictionary header initialization
  treeNode* header[30];
  int i;
  for (i = 0; i < 26; i++) {
    header[i] = NULL;
  }
  // vocabulary read-in
  int numOfWords;
  scanf("%d\n", &numOfWords);

  for (i = 0; i < numOfWords; i++) {
    char current = getchar();                // get the first letter for header
    if (!header[current-97]) {               // determine if the header exists
      header[current-97] = (treeNode*)malloc(sizeof(treeNode));
      header[current-97]->letter = current;
      header[current-97]->appearance = 0;
      header[current-97]->next[0] = NULL;
      header[current-97]->size = 0;
    } 
    treeNode* ptr = header[current-97];      // points to header
    (ptr->appearance)++;
    current = getchar();                     // read the second letter
    int j;
    for (j = 0; current != '\n'; j++) {
      if (ptr->next[0]) {			     
        int j; int found = 0;
	for (j = 0; j < ptr->size; j++) {
 	  if (current == ptr->next[j]->letter) {
	    ptr = ptr->next[j];
	    found = 1;
	    break;
	  }
	}
	if (!found) {
          (ptr->size)++;
          treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	  newNode->letter = current;
	  newNode->appearance = 0;
	  newNode->next[0] = NULL;
          newNode->size = 0;
          ptr->next[ptr->size-1] = newNode;
	  ptr = ptr->next[ptr->size-1];
	}
      } else {
        treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode->letter = current;
        newNode->appearance = 0;
        newNode->next[0] = NULL;
        newNode->size = 0;
        ptr->size = 1; 
        ptr->next[0] = newNode;
        ptr = newNode;
      } (ptr->appearance)++;
      current = getchar();
    } 
  }
  return 0;
}

int lookUp() {
    int found = 0;
    char current = getchar();
    treeNode* ptr = NULL;
    if (header[current-97]) {                   // find the header
      ptr = header[current-97];
      found = 1;
      current = getchar();
    } else return found;
    
    while (current != '\n') {
      if (ptr->next[0]) {
        int k;
        for (k = 0; k < ptr->size; k++) {
	  if (current == ptr->next[k]->letter) {
	    ptr = ptr->next[k];
	    found = 1;
	    break;
	  }
      	}	
      	if (!found) return 0;
      } else break;
      current = getchar();
    }

  return found;
}
