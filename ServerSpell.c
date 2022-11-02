#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sort(char *option);

int main(int argc, char* argv[]){

	if(argc < 2){
		printf("ServerSpell v1.0.0 : no command specified\nTry \'ServerSpell -h\' for more information.\n");
	}else{
		sort(argv[1]);
	}
	return 0;
}

int sort(char *option){

	if(strncmp(option, "-h",sizeof(option))==0){
		printf("ServerSpell v1.0.0\n\nCommands\n\n-h : show command option information\n\n-v : show ServerSpells Version\n\n");
	}else if(strncmp(option,"-v",sizeof(option))==0){
		printf("\nServerSpell Version 1.0.0 Develop by Archan All right Reversed\n\n");
	}else{
		printf("Not invalid Option\n");
	}

	return 0;
}
