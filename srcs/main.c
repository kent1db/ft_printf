#include <stdio.h>

int		main()
{
	int ret1;
	int ret2;

	ret1 = 0;
	ret2 = 0;
	/*printf("both  [%0-20c]\n", 'a');
	printf("minus [%-20c]\n", 'a');
	printf("zero  [%020c]\n", 'a');*/
	/*printf("none  [%20.d]\n", 42);
	printf("neg * [%20.*d]\n", -10, 42);
	printf("0_10  [%20.010d]\n", 42);*/
	ret1 = printf("minus  [%-10.20s]\n", "Hello");
	ret2 = printf("none   [%10.20s]\n", "Hello");
	printf("ret1 = %d\nret2 = %d\n", ret1, ret2);
	return (0);
}