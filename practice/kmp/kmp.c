
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int arr[SIZE] = {79,30,24,48,26,34,5,48,21,86};

KMP(T, P) {
	n = length(T); 
	m = length(P);
	compute_next(P);
	q = 0; // number of characters matched

	// so far
	i=1;
	while (i<=n) {
		// loop until a match is found, or  number of characters matched so far is 0
		// note ’i’ is unchanged.
		while (q > 0 and P[q+1] != T[i]) {
			q=next[q];
		}
		// matched character increased by 1
		if (P[q+1]==T[i]) q=q+1;
		if (q==m) {
			print "Pattern occurs with shift=", i-m
				q=next[q];
		}
		i++;
	}
}
compute_next(P) {
	m = length(P);
	next[1]=0; // initialization
	k = 0; // number of characters matched

	// so far
	q=2;
	while (q<=m) {
		while (k > 0 and P[k+1] != P[q]) {
			k = next[k];
		}
		if (P[k+1]==P[q]) k=k+1;
		next[q]=k;
		q++;
	}
}

int main()
{
	// Print original data
	//printData();

	//quickSort(0, SIZE-1);

	// Print sorted data
	//printData();

	return 0;
}
