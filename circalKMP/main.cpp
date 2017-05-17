#include <stdio.h>
#include <string.h>

#define		DNALIMIT		1000
#define		VIRUSLIMIT		100

char a[DNALIMIT];
char b[VIRUSLIMIT];
int p[VIRUSLIMIT];
int lena, lenb;
void getp()
{
	int i = 0, j = -1;
	p[0] = -1;
	while (i<lenb)
	{
		if (j == -1 || b[i] == b[j])
		{
			i++; j++;
			p[i] = j;
		}
		else
			j = p[j];
	}
}
void kmp()
{
	getp();
	int i = 0, j = 0;
	while (i<2 * lena)
	{
		if (j == -1 || a[i%lena] == b[j])
		{
			i++; j++;
			if (j == lenb)
			{
				printf("yes\n");
				return;
			}
		}
		else
			j = p[j];
	}
	printf("no\n");
}
int main()
{
	while (scanf("%s", a) != EOF)
	{
		scanf("%s", b);
		lena = strlen(a);
		lenb = strlen(b);
		kmp();
	}
	return 0;
}