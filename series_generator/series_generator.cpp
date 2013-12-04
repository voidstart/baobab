#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;
//give me N random number, as an ARRAY
// - memory allocation : fit in RAM, on stack/heap, GC
// - randomness: not exactly random. 2^32 seed, limited random sea.
void append_random_ints(vector<int> & v, int n)
{
	srand( time(NULL));
	for (int i = 0; i < n; ++i)
	{
		v.push_back(rand());
	}

}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	append_random_ints(v,10);

	return 0;
}
