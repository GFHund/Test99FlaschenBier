#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "log.h"

void log(char* string)
{
	//FILE* datei = fopen("./log.txt",w);
	//fseek(datei,0,SEEK_END);
	//fwrite(
	int fd = open("./log.txt",O_WRONLY);
	lseek(fd,0,SEEK_END);
	write(fd,string,sizeof(string));
	close(fd);
}
