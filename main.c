#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "log.h"
#include "calcAreas.h"

typedef void (*logfunc)(char*);

extern void log(char* String);
extern float calcRectArea(float width,float height);

char config[30];

void parsFile()
{
	int fd = open("./config",O_RDWR);
	int i;
	int j=0;
	char state[30];
	char zeichen;
	while(i!=SEEK_END)
	{
		read(fd,(char*)&zeichen,1);
		if(zeichen == '/')
		{
			char zeichen2;
			read(fd,(char *)&zeichen2,1);
			if(zeichen2=='/')
				while(zeichen2!=0x0a)
				{
					read(fd,(char*)&zeichen2,1);
				}
			else
			{
				state[j]=zeichen;
				j++;
			}
		}
		else if(zeichen==':')
		{
			j=0;
			int k;
			for(k=0;k<30;k++)
				state[k]=0;
		}
		else if(zeichen==0x0a)
		{
			break;
		}
		else
		{
			state[j]=zeichen;
			j++;
		}
	}
	close(fd);
	//printf("%s\n",state);
	//return state;
	//ret = state;
	strncpy(config,state,30);
}

int main()
{
	 float erg = calcRectArea(2.0f,2.0f);
	//dlopen für den aufruf dynamischer bibliotheken
	//char* config ;
	parsFile();
	char ausgabe[30];
	
	sprintf(ausgabe,"%f",erg);
	
	logfunc funktion;
	void* handle;
	if(strcmp(config,"console")==0)
	{
		//printf("console");
		handle = dlopen("./logconsole.so",RTLD_LAZY);
	}
	else if(strcmp(config,"file")==0)
	{
		//printf("File");
		handle = dlopen("./logfile.so",RTLD_LAZY);
	}
	else
	{
		//printf("letzterAusweg %s\n",config);
		handle = dlopen("./logconsole.so",RTLD_LAZY);
	}
	
	if(!handle)
	{
		printf("%s\n",dlerror());
		return 1;
	}
	funktion = dlsym(handle,"log");
	
	funktion(ausgabe);
	
	
	dlclose(handle);
}