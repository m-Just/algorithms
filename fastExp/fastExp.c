/* Fast Exponential Calculator
 * Take two integer inputs:
 * base number (all 64-bits integers) and power number (non-negative integers),
 * Set the buffer to the value of the exponential term MOD (by 10e9 + 7).
 */
 
#include "fastExp.h"

long long fastExp(long long base, int exp, long long* ans_buff) {
	long long result = 1;
	int i;
	if (exp < 0) return 0;
	for (i = 0; 1; i++) {
		int k = exp & 1;
		exp >>= 1;
		if (k == 1) {
			result *= base;
			result %= MOD;
		}
		base *= base;
		base %= MOD;
		if (exp == 0) break;
	}
	*ans_buff = result;

	return 1;
}
