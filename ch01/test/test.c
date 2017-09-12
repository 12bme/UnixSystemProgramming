#include <unistd.h>
#include <stdio.h>
#include <errno.h>

extern int errno;

int main(void) {

	if(1) {
		printf("errno=%d\n", errno);
	}

	return 0;

}
