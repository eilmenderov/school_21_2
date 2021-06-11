#include <stdio.h>
#include <stdlib.h>

void f(void)
{
	static char *a;

	a = malloc(15);
	a = "1234567890qwe";
	a[0] = a[0] + 1;
	printf("%s\t", a);
}

int main(void)
{
	int			i = 0;

	while (i < 5)
	{
		f();
		i++;
	}
}