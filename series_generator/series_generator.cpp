#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
	srand( time(NULL));
	int num = rand();
	printf("%d\n", num);
	return 0;
}
