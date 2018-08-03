
#include <stdio.h>
#include <stdlib.h>



void horspool_pre(char *p, int p_size, int *t, int t_size)
{
	int i;
	for (i=0; i<t_size; i++)
		t[i] = p_size;

	for (i=0; i<p_size-1; i++)
		t[p[i]] = p_size-i-1;
}

void horspool(char *s, int s_size, char *p, int p_size)
{
	int i = 0, j;
	int t[257] = {0,};

	horspool_pre(p, p_size, t, 256);

	while (i <= s_size - p_size)
	{
		j = p_size-1;
		while (j >= 0 && p[j] == s[i+j])
			j--;

		if (j<0)
			printf("Matched in %d", i);

		i += t[s[i+p_size-1]];
	}

}


void kmp_pre(char *p, int size, int table[]) {
	int i = 0;
	int j = table[0] = -1;
	while (i < size) {
		while (j > -1 && p[i] != p[j])
			j = table[j];
		i++;
		j++;
		if (p[i] == p[j])
			table[i] = table[j];
		else
			table[i] = j;
	}
}


void kmp(char *p, int p_size, char *s, int s_size) {
	int i, j, table[p_size+1];

	kmp_pre(p, p_size, table);

	i = j = 0;
	while (j < s_size) {
		while (i > -1 && p[i] != s[j])
			i = table[i];
		i++;
		j++;
		if (i >= p_size) {
			printf("Matched in %d", j-i);
			i = table[i];
		}
	}
}


int main()
{
	// Print original data
	//printData();
	char str[100];
	char pt[10];
	int str_size, pt_size;

	horspool(str, str_size, pt, pt_size);

	// Print sorted data
	//printData();

	return 0;
}
