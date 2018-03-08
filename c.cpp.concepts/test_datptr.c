#include <stdio.h>
#define DL 1
void function1();
void function2(UINT8 data_len, UINT8 *dataptr);
void function3(UINT8 data_len, UINT8 *dataptr);

void main()
{
	function1();

    return;
}

void function1()
{
	UINT8  data[DL];
	UINT8  len=DL;

	for(i=0; i<len; i++)
		data[i] = i;
	function2(len, data);
}

void function2(UINT8 data_len, UINT8 *dataptr)
{
	int i;

	printf("In function 2\n");
	for(i=0; i<data_len; i++)
	{
	    printf("byte%u: %u\n", i, *dataptr );
	    dataptr++;
	}
	
	function3(data_len, *dataptr);
}

void function3(UINT8 data_len, UINT8 *dataptr)
{
	int i;
	
	printf("In function 3\n");
	for(i=0; i<data_len; i++)
	{
	    printf("byte%u: %u\n", i, *dataptr );
	    dataptr++;
	}
}