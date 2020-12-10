#include <stdio.h>

int		main()
{
	printf("both  [%0-20c]\n", 'a');
	printf("minus [%-20c]\n", 'a');
	printf("zero  [%020c]\n", 'a');
	printf("none  [%20c]\n", 'a');
	ftprintf("both  [%0-20c]\n", 'a');
	ftprintf("minus [%-20c]\n", 'a');
	ftprintf("zero  [%020c]\n", 'a');
	ftprintf("none  [%20c]\n", 'a');
	return (0);
}