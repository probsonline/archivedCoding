#define INT_SRAM_BASE           0x50000000   
#define INT_SRAM_SIZE           0x00010000   
#define INT_SRAM_VALID          0x00000001   

void main()
{
unsigned long a=0;


	printf("----\n");
	printf("%x 	\n", INT_SRAM_BASE);
	printf("%x 	\n", INT_SRAM_VALID);
	a = INT_SRAM_BASE|INT_SRAM_VALID;
	printf("%x \n", a);
	a = INT_SRAM_BASE!INT_SRAM_VALID;
	printf("%x \n", a);

}