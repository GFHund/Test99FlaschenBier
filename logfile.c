#include <sys/types.h>
#include <sys/state.h>
#include <fcntl.h>
#include <unistd.h>

void log(char* string)
{
	//FILE* datei = fopen("./log.txt",w);
	//fseek(datei,0,SEEK_END);
	//fwrite(
	int fd = open("./log.txt",0_WRONLY);
	lseek(fd,0,SEEK_END);
	write(fd,string,sizeof(string));
	close(fd);
}