//When compiling use gcc protomain.c hashfun.o to include the hash function from the 10/10 lecture
//When running use ./a.out *some number* where *some number* = the number to be converted to the correct letters
//This program accepts a predetermined hash at the command line and converts it to the correct letters

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

unsigned long long hash(char *str); //hash function in hash.o

int main(int argc, char *argv[]) //bring in command line number
{
    char testString[5];
    int flag = 0;
    unsigned long long argument;
    unsigned long long returnHash;
    time_t start=0;
   time_t stop=0;
   double timeTaken=0;
    argument = strtol(argv[1], NULL, 10); //convert command line argument to a long for comparison

    testString[0] = 'a'; //set characters to a
    testString[1] = 'a';
    testString[2] = 'a';

    start = clock();
    while(testString[0] <= 'z') //loop through letters until 'z'
    {
        while(testString[1] <= 'z')
        {
            while(testString[2] <= 'z')
            {
                returnHash = hash(testString); //send each testString to hash function and save in returnHash
                if( returnHash == argument) //compare the returned hash number to the original hash argument number
                {
                    printf("Answer Found: %s\n", testString); //print answer when found
                    testString[0] = '{'; //break loops since answer found, '{' > 'z' in ASCII
                    testString[1] = '{';
                    testString[2] = '{';
		    flag = 1;
                }
                testString[2]++; //increase letter by 1
            }
            testString[2] = 'a'; //return to a
            testString[1]++;
        }
        testString[1] = 'a';
        testString[0]++;
    }
stop = clock();
       
	if(flag == 1)
        {
          timeTaken =  (stop-start)/(double)CLOCKS_PER_SEC;
	  printf("Time: %16.21f seconds\n", timeTaken);
        }
    return 0;

}
