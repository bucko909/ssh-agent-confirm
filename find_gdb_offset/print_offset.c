#include <stdio.h>

long long int getoffset(void);

int main(int argc, char **argv) {
	printf("%llu\n", getoffset() / sizeof(void *));
}
