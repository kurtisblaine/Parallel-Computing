#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

unsigned long long hash(char *str); //hash function in hash.o

int main(int argc, char *argv[]) //bring in command line number
{
    int testInt[5];
	unsigned long long argument;
    unsigned long long returnHash;

 	testInt[0] = 0; //set characters to a
	testInt[1] = 1;
	testInt[2] = 2;
	testInt[3] = 3;
	int Userinput;

    while(1) //loop through letters until 'z'
    {
		printf("press any to start\n");
		scanf("%d", &Userinput);
			for(int i =0; i<= 9; i++){
				printf("%d", i);
				for(int j =0; j<= 9; j++){
					printf("%d", j);
					for(int k =0;k<= 9;k++){
						printf("%d", k);
							for(int l =0; l<= 9; l++){
								printf("%d", l);
							}
					}
				}
		printf("\n");
		}
    }

    return 0;

}
