#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bconv.h"

char *btable = "0123456789ABCDEF";

char * decimal_to_base(int base, long long value, char *buffer) {
	int len, j;
	double i;
	
	/* Init Buffer */
	*buffer = '\0';
	
	/* Eval output length */
	for(len = 1; value >= pow(base, len); len++);
	
	/* Reversing couting */
	j = 0;
	i = pow(base, len);
	
	while(len--) {
		i /= base;
		
		*(buffer + j++) = btable[(int)(value / i)];
		
		if(value / i >= 1)
			value -= ((int)(value / i) * i);
	}
	
	/* End of buffer */
	*(buffer + j) = '\0';
	
	return buffer;
}

char * basename_of(char base) {
	if(base == BASE_BINARY)
		return "binary";
	
	if(base == BASE_OCTAL)
		return "octal";
	
	if(base == BASE_DECIMAL)
		return "decimal";
	
	if(base == BASE_HEXA)
		return "hexadecimal";
	
	return "unknown";
}

void print_usage(char *basename) {
	fprintf(stderr, "Usage: %s [-b | -o | -d | -h] value\n\n", basename);
		
	fprintf(stderr, "Prefix options:\n");
	fprintf(stderr, " -b: binary\n");
	fprintf(stderr, " -o: octal\n");
	fprintf(stderr, " -d: decimal (default)\n");
	fprintf(stderr, " -h: hexadecimal\n\n");
	
	fprintf(stderr, "Note: Hexadecimal value can be passed with 0x prefix\n");
}

int main(int argc, char *argv[]) {
	char type, buffer[128];
	long long value = 0;
	
	/* Checking arguments */
	if(argc < 2) {
		print_usage(argv[0]);
		return 1;
	}
	
	/* Checking input type */
	if(*argv[1] == '-') {
		if(argc < 3) {
			print_usage(argv[0]);
			return 1;
		}
	
		/* Checking type */
		switch(*(argv[1] + 1)) {
			case 'b':
				type  = BASE_BINARY;
				value = strtol(argv[2], NULL, BASE_BINARY);
			break;
			
			case 'o':
				type = BASE_OCTAL;
				value = strtol(argv[2], NULL, BASE_OCTAL);
			break;
			
			case 'h':
				type = BASE_HEXA;
				value = strtol(argv[2], NULL, BASE_HEXA);
			break;
			
			default:
				type = BASE_DECIMAL;
				value = atoll(argv[2]);
		}
	} else {
		/* Hexadecimal with 0x prefix */
		if(*argv[1] == '0' && *(argv[1] + 1) == 'x') {
			type = BASE_HEXA;
			value = strtol(argv[1] + 2, NULL, BASE_HEXA);
		
		/* Decimal */
		} else {
			type = BASE_DECIMAL;
			value = atoll(argv[1]);
		}
	}
	
	
	printf("Input base: %s\n\n", basename_of(type));
	
	printf("Binary  : %s\n", decimal_to_base(BASE_BINARY, value, buffer));
	printf("Octal   : %s\n", decimal_to_base(BASE_OCTAL, value, buffer));
	printf("Decimal : %lld\n", value);
	printf("Hexa    : %s (0x%s)\n", decimal_to_base(BASE_HEXA, value, buffer), buffer);
	
	return 0;
}
