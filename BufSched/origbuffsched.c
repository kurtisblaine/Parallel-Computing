#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int buff[10] = {3,1,1,2,5,4,2,1,1,3};
int next;

int get_next()
{
	int assign;
	assign = next;
	next++;
	if(next > 10) assign = -1;
	return assign;
}

void working( int me )
{
	int mytask;
	int dur;
	printf("%d getting a job\n", me);
	mytask = get_next();
	while ( mytask != -1 )
	{
		dur = buff[mytask];
		printf("%d doing task %d ... so sleep %d\n", me, mytask, dur);
		sleep( dur );	
		printf("%d sleeping complete\n", me);

		mytask = get_next();
	}	
	printf("xxxxxxxxxxxxx %d\n", me);
}

int main()
{
	int i;

	i = 1;
	working( i );
	return 0;
}
