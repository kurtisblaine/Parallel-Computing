/When compiling use gcc protomain.c hashfun.o to include the hash function from the 10/10 lecture
//When running use ./a.out *some number* where *some number* = the number to be converted to the correct$
//This program accepts a predetermined hash at the command line and converts it to the correct letters

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned long long hash(char *str); //hash function in hash.o

int main(int argc, char *argv[]) //bring in command line number
{
    char testString[5];
        unsigned long long int argument;
    unsigned long long returnHash;
        bool isFound = false; 
   // argument = strtol(argv[1], NULL, 10); //convert command line argument to a long for comparison

        testString[0] = 'a'; //set characters to a
        testString[1] = 'a';
        testString[2] = 'a';
        testString[3] = 'a';
while(isFound == false){
        scanf("%lld", &argument);
    while(testString[0] <= 'z') //loop through letters until 'z'
    {
                while(testString[1] <= 'z')
                {
            while(testString[2] <= 'z')
            {
                while(testString[3] <= 'z')
                {
                                        returnHash = hash(testString); //send testString to hash functio$
                                        if( returnHash == argument) //compare the returned number to the$
                                        {
                                                printf("Answer Found: %s\n", testString); //print answer$
                                                testString[0] = '{'; //break loops since answer found, '$
                                                testString[1] = '{';
                                                testString[2] = '{';
                                                testString[3] = '{';
                                                isFound = true;
//                                              printf("");  

                                        }
                                        else{
                                                printf("-1\n");
                                        }
                                        testString[3]++; //increase letter by 1
                                }
                                testString[3] = 'a'; //return to a
                                testString[2]++;
                        }
                        testString[2] = 'a';
                        testString[1]++;
                }
                testString[1] = 'a';
                testString[0]++;
    }
}
    return 0;

}
