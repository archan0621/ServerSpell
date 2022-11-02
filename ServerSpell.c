#include <stdio.h>
#include <string.h>`
#include <stdlib.h>

int main(int argc, char* argv[]){

	if(argc < 2){
		printf("옵션을 입력해주세요\n");
	}else{
		if(strcmp(argv[1],"-h") == 0){
			printf(" this is a help \n");
		}else{
			for(int i=0; i < argc ; i++){
                		printf("argv[%d]은 %s입니다.\n",i,argv[i]);
        	}
        		printf("argc는 %d개 입니다.\n", argc);
		}
	}

	return 0;
	
}
