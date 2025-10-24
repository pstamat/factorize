/* File: factorize.c */

/* Factorizes all numbers in a range */

#include <stdio.h>

int main()
{
	int minnum, maxnum, num, temp, factor;
	printf("Please, give minimum number: ");
	scanf("%d", &minnum);
	printf("Please, give maximum number: ");
	scanf("%d", &maxnum);
	for (num = minnum ; num <= maxnum ; num++) {
		printf("Prime factors of %d are:", num);
		temp = num;
		factor = 2;	// Start with 2 as possible factor
		while (factor * factor <= temp) {
				// Check candidate factors up to the square root
			while (temp % factor == 0) {
				printf(" %d", factor);
				temp /= factor;
			}
			if (factor == 2) {
				factor = 3;	// Next factor to check is 3
			}
			else if (factor % 6 == 1) {
				factor += 4;	// Next of 7 is 11, of 13 is 17, etc.
			}
			else {
				factor += 2;
					// Next of 3 is 5, of 5 is 7, of 11 is 13, etc.
			}
		}
		if (temp != 1) {	// Is final temp a prime factor?
			printf(" %d", temp);
		}
		printf("\n");
	}
	return 0;
}
