#include "fastExp.h"

int main() {
  long long base, ans;
  int power;
  
  scanf("%lld %d", &base, &power);
  if (fastExp(base, power, &ans)) printf("%lld\n", ans);
  else return -1;
  return 0;
}
