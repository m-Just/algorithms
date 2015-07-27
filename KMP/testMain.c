#include <KMP.h>

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
