
typedef unsigned char   UINT8;
typedef unsigned short  UINT16; 
typedef unsigned long   UINT32;
typedef unsigned int    UNSIGNED;
typedef int             INT;


UINT16 mul(UINT8 x, UINT8 y);
UINT16 mul_2(UINT8 x, UINT8 y);


#define my_mul(x)  mul_2(x, 2)