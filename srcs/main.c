#include <stdio.h>

int		main()
{
	int ret1;
	int ret2;

	ret1 = 0;
	ret2 = 0;
	//ret1 = printf("minus [%-.s]\n", "Hello");
	ret1 = printf("none [%10.9d]\n", 12345678);
	return (0);
}