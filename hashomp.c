#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

unsigned long long hash(char *str); //hash function in hash.o

int main(int argc, char *argv[]) //bring in command line number
 {
    char testString[5];
    unsigned long long argument;
    unsigned long long returnHash;
    int flag = 0;
    argument = strtol(argv[1], NULL, 10); //convert command line argument to a long for comparison
   // testString[0] = 'a'; //set characters to a
   // testString[1] = 'a';
   // testString[2] = 'a';
    char  i, j, k;
    time_t start, stop;


start = clock();
#pragma omp parallel for
   // while(testString[0] <= 'z') //loop through letters until 'z'
   for(i = 'a'; i <= 'z'; i++)
     {
        testString[0] = i;


       // while(testString[1] <= 'z')
        for(j = 'a' ; j <='z'; j++)
        {
         testString[1] = j;


           // while(testString[2] <= 'z')
            for( k = 'a'; k <= 'z'; k++)
            {
                testString[2] = k;

                returnHash = hash(testString); //send each testString to hash function and save in returnHash
                if( returnHash == argument) //compare the returned hash number to the original hash argument number
                {
                   // printf("Answer Found: %s\n", testString); //print answer when found
                    flag = 1;

                    i = 'z'; //break loops since answer found, '{' > 'z' in ASCII
                    j = 'z';//testString[1] = '{';
                    k = 'z';//testString[2] = '{';


                }
               // testString[2]++; //increase letter by 1
            }
             k = 'a';
            //testString[2] = 'a'; //return to a
            //testString[1]++;
        }
        j = 'a';
       // testString[1] = 'a';
        //testString[0]++;

    }
stop = clock();

        if(flag == 1)
        {
          printf("Answer Found: %s\n", testString);
          printf("Time: %f\n", (stop-start)/(double)CLOCKS_PER_SEC);
        }


    return 0;
}
