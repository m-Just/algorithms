#include <stdio.h>
#include <string.h>

void getNext2(char* ss, int len, int* next);

int main() {
  char pri_str[1000], mod_str[1000];
  scanf("%s", pri_str); getchar();
  scanf("%s", mod_str); getchar();

  /* KMP */
  int next[strlen(mod_str)+1];
  getNext2(mod_str, strlen(mod_str), next);

  int i = 0, j = 0;
  int mlen = strlen(mod_str);
  int plen = strlen(pri_str);

  while (i + mlen <= plen) {
    while (j < mlen && pri_str[i] == mod_str[j]){
      i++; j++;
      if (j == mlen) printf("Found match at position %d\n", i-j+1);
    }
    if (i == plen) break;
    i -= next[j]; j = 0;
  }

  return 0;
}

void getNext(char* s, int len, int* next) {
  int i, j; next[0] = -1; next[1] = 0;
  for (i = 1; i < len; i++) {
    for (j = 0; i+j < len; j++) {  // this inner loop is redundant
      if (s[j] == s[i+j] && next[i+j+1] > j+1) next[i+j+1] = j+1;
      else { next[i+j+1] = 0; break; }
    }
  }
}

void getNext2(char* ss, int len, int* next) {
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
