#include <stdio.h>
#include <string.h>

int kmp(char* mod_str, char* pri_str);
void getNext(char* ss, int len, int* next);
