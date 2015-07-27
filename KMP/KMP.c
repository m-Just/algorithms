/* KMP algorithm used to search for certain
 * substring matches in a large string */ 
 
#include <KMP.h>
  
int kmp(char* mod_str, char* pri_str) {
  int mlen = strlen(mod_str);
  int plen = strlen(pri_str);
  
  if (mlen > plen) {
    printf("Error: the length of model string is bigger than the primary string.\n");
    printf("Search aborts.\n");
    return 0;
  }
  
  int next[mlen+1];
  getNext(mod_str, mlen, next);

  int i = 0, j = 0;
  while (i + mlen <= plen) {
    while (j < mlen && pri_str[i] == mod_str[j]){
      i++; j++;
      if (j == mlen) printf("Found match at position %d\n", i-j+1);
    }
    if (i == plen) break;
    i -= next[j]; j = 0;
  }
  
  return 1;
}

void getNext(char* ss, int len, int* next) {
  int j = -1, i = 0;
  next[0] = -1;
  while(i < len) {
    if(j == -1 || ss[i] == ss[j]) {
      i++; j++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
}
