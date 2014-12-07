#include <net/af_unix.h>

long long int getoffset(void) {
	return (long long int)&((struct unix_sock *)NULL)->peer;
}
