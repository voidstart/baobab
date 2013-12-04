#include "stdio.h"
#include <string.h>

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
			// printf("Looking at end: a[%d] (= %d)\n",end, a[end] );
			//optimal case : payload just fits the end

			if ( a[end] <= to_insert )
			{
				// printf("optimal (%d <= %d): to_insert(= %d) is biggest, no shuffle\n",
				// 	a[end], to_insert,
				// 	to_insert);
				// pos_to_put = end+1; // put right after sorted end
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

		// printf("Sorted size: %d\n", sorted_n );
		print_a(o);

	}
}

void bubble_sort_a(int a[])
{
	int n_passes = N; // each pass get one max
	for (int i = 0; i < n_passes; ++i)
	{
		int bubble = a[0]; // this bubble gets bigger along the line
		int run_len = N - i; // each run is getting shorter, the ending part get sorted
		for (int j = 0; j < run_len; ++j)
		{
			if (a[j] < bubble) // bubble shifts right
			{
				a[j-1] = a[j];
				a[j] = bubble;
			}
			else // found new bubble ( bigger than the old bubble )
			{
				bubble = a[j];
			}
			// print_a(a);
		}
		print_a(a);
	}
}

void selection_sort_a(int a[])
{
	int n_passes = N; // N selects (each select one max)

	// put selection result at the end of array
	for (int i = 0; i < n_passes; ++i)
	{
		int num_to_select = N - i; // keep max at end, each round get smaller
		int select_result_index = num_to_select-1;
		int select_index = 0;
		for (int j = 0; j < num_to_select; ++j)
		{
			if (a[j] > a[select_index])
			{
				select_index = j;
			}
		}

		// printf("selected index: %d\n", select_index);

		int tmp = a[select_result_index];
		// printf("tmp: %d\n", tmp);
		a[select_result_index] = a[select_index];
		a[select_index] = tmp;

		print_a(a);
	}
}

void swap_a(int a[], int x, int y)
{
	int tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

void merge_a(int a[], int start, int first_half_end, int second_half_end)
{
	// first_half_end : end index of 1st half. So on.

	// select the higher of two halves, then put at the end
	int size = second_half_end - start +1;
	int * w = new int[size]; 

	// keep track of walking
	int m1 = first_half_end;
	int m2 = second_half_end;
	int mw = size-1;

	while ( true )
	{
		bool m1_valid = (m1 >= start);
		bool m2_valid = (m2 > first_half_end);
		if ( m1_valid && m2_valid)
		{
			if (a[m1]>a[m2])
			{
				w[mw] = a[m1];
				m1 -= 1;
			}
			else
			{
				w[mw] = a[m2];
				m2 -= 1;
			}
		}
		else if (m1_valid && !m2_valid)
		{
			w[mw] = a[m1];
			m1 -= 1;
		}
		else if (!m1_valid && m2_valid)
		{
			w[mw] = a[m2];
			m2 -= 1;
		}
		else // end of both halves
		{
			break;
		}

		mw -= 1;
	}

	// copy result
	memcpy(a+start, w, sizeof(int) * size);

	delete[] w;
}

void merge_sort_sub_a( int a[], int start, int end )
{
	int diff = end - start;
	if ( diff == 0)
	{
		return;
	}
	if ( diff == 1 )
	{
		if ( a[start] < a [end])
			return;
		else
			swap_a(a, start, end);
	}

	int mid = (start + end)/2;
	// printf("mid: %d, start: %d, end: %d\n", mid, start, end );
	merge_sort_sub_a(a, start, mid );
	merge_sort_sub_a(a,mid+1, end );

// printf("before merge\n");
	print_a(a);

	merge_a(a, start, mid, end);
// printf("after merge\n");

	print_a(a);

}

void merge_sort_a(int a[])
{
	int n = N;
	merge_sort_sub_a(a, 0, n-1);
}

int main(int argc, char const *argv[])
{
	print_a(o);
	// insert_sort_a(o);
	// bubble_sort_a(o);
	// selection_sort_a(o);
	merge_sort_a(o);
	//print_a(r);
	return 0;
}
