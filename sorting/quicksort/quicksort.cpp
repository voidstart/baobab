#include "stdio.h"

#define N 11


// o-rigin, r-esult
int o[N] = { 30, 90, 60, 50, 70, 10, 160, 20, 40, 100, 80 };
int r[N] = { 0 };

// a-rray
void print_a(int a[])
{
	int n = N;

	printf("a = [");
	for (int i = 0; i < n; ++i)
	{
		if (i>0)
			printf(",");

		printf("% 4d", a[i]);

	}
	printf("]\n");
}

void insert_sort_a(int a[])
{
	int n = N;
	int sorted_n = 0;

	for (int i = 0; i < n; ++i)
	{
		int to_insert = a[i]; // the "payload"
		int pos_to_put = i; // initial try to put at the end of sorted
		// look from the end of sorted
		for (int j = 0; j < sorted_n; ++j)
		{
			int end = sorted_n-1 - j; // reverse index
			printf("Looking at end: a[%d] (= %d)\n",end, a[end] );
			//optimal case : payload just fits the end

			if ( a[end] <= to_insert )
			{
				printf("optimal (%d <= %d): to_insert(= %d) is biggest, no shuffle\n",
					a[end], to_insert,
					to_insert);
				pos_to_put = end+1; // put right after sorted end
				break; // 
			}
			else
			{
				//shifting right
				a[end+1] = a[end];
				pos_to_put -= 1;
			}
		}
		a[pos_to_put] = to_insert; // deliver payload


		sorted_n = sorted_n + 1;

		printf("Sorted size: %d\n", sorted_n );
		print_a(o);

	}
}

int main(int argc, char const *argv[])
{
	print_a(o);
	insert_sort_a(o);
	//print_a(r);
	return 0;
}
