#include "stdio.h"




int a[] = { 30, 90, 60, 50, 70, 10, 160, 20, 40, 100, 80 };

void print_a()
{
	int n = sizeof(a)/sizeof(int);

	printf("a = [");
	for (int i = 0; i < n; ++i)
	{
		if (i>0)
			printf(",");

		printf("% 3d", a[i]);

	}
	printf("]\n");



}


int main(int argc, char const *argv[])
{
	print_a();
	return 0;
}
