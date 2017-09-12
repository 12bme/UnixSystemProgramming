#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	int fd;
	mode_t mode;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	// 소유자 읽기 권한 | 소유자 쓰기 권한 | 그룹 읽기 권한 | 기타 사용자 읽기 권한

	fd = open("unix.txt", O_CREAT, mode);
	if(fd == -1) {
		perror("Create");
		exit(1);
	}
	close(fd);

	return 0;

}
