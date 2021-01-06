#include "part_of_the_matrix.h"

void mx_printstr(const char *s) {
	const char *temp = s;
	int length = 0;

	for (; *temp++;) {
		length++;
	}
	
	write(1, s, length);
}
