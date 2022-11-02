#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sort(int param, char *option);
int create_config(char* path);

typedef struct _Config {
	char* location;
}Config;

int main(int argc, char* argv[]){

	if(argc < 2){
		printf("ServerSpell v1.0.0 : no command specified\nTry \'ServerSpell -h\' for more information.\n");
	}else{
		sort(argc, argv[1]);
	}
	return 0;
}

int sort(int param, char *option){

	if(strncmp(option, "-h",sizeof(option))==0){
		printf("ServerSpell v1.0.0\n\nCommands\n\n-h : show command option information\n\n-v : show ServerSpells Version\n\n-r [jarName] : Register jar to run\n\n");
		printf("-init : Create conf file and initialize settings\n\n");
	}else if(strncmp(option,"-v",sizeof(option))==0){
		printf("\nServerSpell Version 1.0.0 Develop by Archan All right Reversed\n\n");
	}else if(strncmp(option,"-r",sizeof(option))==0){
		if(param < 3){
			printf("\nServerSpell v1.0.0 : Option \"-r\" requires an argument\n\n");
		}else{
			printf("wow\n");
		}
	}else if(strncmp(option,"-init",sizeof(option))==0){
		create_config("ServerSpell.conf");
	}else{
		printf("Not valid Option\n");
	}

	return 0;
}

int create_config(char* path){

	printf("Conf file create at \"%s\"\n", path);

	FILE* stream = NULL;
	stream = fopen(path, "w");

	if(stream == NULL){
		printf("Error : Can't create file\n");
		return 0;
	}else{
	printf("Successfully create Conf file\n");
	fprintf(stream, "\n%s\n", "#Location for Jar File");
	fprintf(stream, "%s%s\n", "Location:", " ");
}
	fclose(stream);
	return 0;
}
