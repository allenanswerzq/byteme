#include <stdio.h>

int find(int *A, int N)
{
	int max = 0, tmp = 0;
	for (int i=0; i<N; i++)
		if (A[i] == 1) 
		{
			tmp++;
			max = max > tmp ? max : tmp;
		}
		else
			tmp = 0;
	return max;
}


void main()
{
	int A[] = {1, 0, 1, 1, 0, 1};
	int B[] = {1, 0, 1, 1, 1, 0};
	printf("%d\n", find(A, 6));
	printf("%d\n", find(B, 6));
}
