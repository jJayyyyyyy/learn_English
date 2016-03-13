#include <stdio.h>

int main(int argc, char * argv[])
{
	if(argc == 1){
		printf("Hi, there!\n");
	}else{
		printf("hi, %s\n", argv[1]);
	}
	
}
