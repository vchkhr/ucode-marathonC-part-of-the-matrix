#include "part_of_the_matrix.h"

long long mx_atoi(const char *str) {
	const char* buffer;
	while(mx_isspace(*str)) {
		str++;
	}
	long long num = 0;
	int digit = (str[0] == '-') ? -1 : 1;
	if (!(str[0] >= '0' && str[0] <= '9') && str[0] != '-' && str[0] != '+') {
		return 0;
	}
	if (str[0] == '-' || str[0] == '+') {
		str++;
	}
	buffer = str;
	while(*buffer >= '0' && *buffer <= '9') {
		num *= 10;
		num += *buffer - '0';
		buffer++;
	}
	if (*buffer != '\0') {
		return 0;
	}
	return num * digit;
}
