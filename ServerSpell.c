#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#define _GNU_SOURCE

int sort(int param, char *option, char *soption);
int create_config(char* path);
int registerJar(char* path, char* jar);
int startJar();
int showLog();
int stopJar();

int main(int argc, char* argv[]){

	// Config set;

	// Config_Read(&set, "ServerSpell.conf");
	if(argc < 2){
		printf("ServerSpell v1.0.0 : no command specified\nTry \'ServerSpell -h\' for more information.\n");
	}else{
		sort(argc, argv[1], argv[2]);
	}
	return 0;
}

int sort(int param, char *option, char *soption){

	if(strncmp(option, "-h",sizeof(option))==0){
		printf("ServerSpell v1.0.0\n\nCommands\n\n-h : show command option information\n\n-v : show ServerSpells Version\n\n-r [jarName] : Register jar to run\n\n");
		printf("--start : Run jar server\n\n--log : Show log for jar server\n\n--stop : Stop jar Server\n\n");
	}else if(strncmp(option,"-v",sizeof(option))==0){
		printf("\nServerSpell Version 1.0.0 Develop by Archan All right Reversed\n\n");
	}else if(strncmp(option,"-r",sizeof(option))==0){
		if(param == 3){
			registerJar("ServerSpell.conf", soption);
		}else{
			printf("\nServerSpell v1.0.0 : Option \"-r\" invalid argument\n\nPlease check ServerSpell -h\n\n");
		}
	}else if(strncmp(option,"--start",sizeof(option))==0){
		startJar();
	}else if(strncmp(option,"--log",sizeof(option))==0){
		showLog();
	}else if(strncmp(option,"--stop",sizeof(option))==0){
		stopJar();
	}else{
		printf("Not valid Option\n");
	}

	return 0;
}

int registerJar(char* path, char* jar) {

	int fd;

	printf("Conf file create at \"%s\"\n", path);

	FILE* stream = NULL;
	stream = fopen(path, "w");

	if(stream == NULL){
		printf("Error : Can't create file\n");
		return 0;
	}else{
	printf("Successfully create Conf file\n");
	fprintf(stream, "%s\n", jar);
}
	fclose(stream);
	return 0;
}

int startJar(){
	
	FILE* stream = NULL;
	stream = fopen("ServerSpell.conf", "r");

	if(stream == NULL){
		printf("Error : Can't open file Please register jar file\n");
		return 0;
	}else{
		char line[256];
		char command[256];
		size_t len = 0;

		while(fgets(line, sizeof(line), stream) != NULL){
			line[strlen(line) - 1] = '\0';
			printf("Command executed: nohup java -jar %s &\n", line);
			sprintf(command, "nohup java -jar %s &", line);
			system(command);
			printf("Starting jar file named %s\n", line);
			printf("Please use --log to see log\n");
		}
	}
	fclose(stream);
	return 0;
}

int showLog(){
	system("tail -f nohup.out");
	return 0;
}

int stopJar(){
	FILE* stream = NULL;
	stream = fopen("ServerSpell.conf", "r");

	if(stream == NULL){
		printf("Error : Can't open file Please register jar file\n");
		return 0;
	}else{
		char line[256];
		char command[256];
		size_t len = 0;

		while(fgets(line, sizeof(line), stream) != NULL){
			line[strlen(line) - 1] = '\0';
			//find proccess pid with jar name
			sprintf(command, "ps -ef | grep %s | grep -v grep | awk '{print $2}'", line);
			FILE* stream = popen(command, "r");
			char pid[256];
			fgets(pid, sizeof(pid), stream);
			pid[strlen(pid) - 1] = '\0';
			printf("Command executed: kill -9 %s\n", pid);
			sprintf(command, "kill -9 %s", pid);
			system(command);
			printf("Stopping jar file named %s\n", line);
		}
	}
	fclose(stream);
	return 0;
}