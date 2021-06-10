#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char **argv){

	int fd_in, fd_out, size;
	char buf[1024];

	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[2], O_WRONLY | O_CREAT, 00600);

	if (fd_in < 0){
		printf("open input failed.");
		return 0;
	}
	if (fd_out < 0){
		printf("open output failed");
		return 0;
	}

	while(1){
		size = read(fd_in, buf, 1024);
		if (size <= 0){
			break;
		}
		write(fd_out, buf, size);
	}

	close(fd_in);
	close(fd_out);
}
