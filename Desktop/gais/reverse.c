#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char **argv){

	int fd_in, size;
	fd_in = open(argv[1], O_RDWR);

	struct stat st;
	stat(argv[1], &st);
	size = st.st_size;

	for (int i = 0; i < size / 2; i++){

		char front[10] = {0};
		char back[10] = {0};

		lseek(fd_in, i, SEEK_SET);
		read(fd_in, front, 1);

		lseek(fd_in, (i * -1) - 1, SEEK_END);
		read(fd_in, back, 1);

		lseek(fd_in, (i * -1) - 1, SEEK_END);
		write(fd_in, front, 1);

		lseek(fd_in, i, SEEK_SET);
		write(fd_in, back, 1);

	}
	close(fd_in);
}
