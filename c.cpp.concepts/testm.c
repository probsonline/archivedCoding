#include <stdio.h>
#include <math.h>

/* Value of PI */
#define     PI      3.14159
#define     TRUE    1
#define     FALSE   0

/* Value of this indicates the n for n-point DFT. */
#define X_POINT_DFT 16

typedef unsigned char BOOLEAN ;
/* Structure for handling Complex Numbers. */
typedef struct COMPLEX_STRUCT
{
	double real;
	double imag;	

} COMPLEX;

/* Array of Complex Number containing the FFT constants. */
COMPLEX fft_constants[];

/* Function prototypes. */
void    FFT_Program_Info(void);
BOOLEAN FFT_Check_PowerOfTwo(int nPoint);
void    FFT_Calculate_Butterfly();
COMPLEX FFT_Calculate_Twiddle_Value(int power, int sample_pt);
void    FFT_Print_Input(int *samples, int sample_count);
//int    *FFT_Reorder_Input(int *in_sequence, int *reordered_sequence);
void    FFT_Reorder_Input(int *in_sequence, int *reordered_sequence, long sample_count);
void    FFT_Reverse_Bit_Sequence(int n, int *rev_n);

int     Min_Bits_For_n;

/* Main function to test the algorithm. */
int main()
{
    COMPLEX Wn;
    int nPoint, i, sample_point=X_POINT_DFT;
    BOOLEAN  flag;
    int *xn;   /* Input Sequence. */
    int *reordered_xn;

    /* Print the purpose of the program. */
//    FFT_Program_Info();
    printf("Enter the value of n for n-point DFT.\n");
    scanf("%d", &nPoint);

    FFT_Reverse_Bit_Sequence(nPoint, &sample_point);
    printf("reversed : %d ", sample_point);

#if 0
    /* Check if the value entered is a power of 2. */
    flag = FFT_Check_PowerOfTwo(nPoint);

    if (flag) 
    {
        /* Try to allocate the memory if input number is proper. */
        xn = (int *)malloc(nPoint * sizeof(int));
        reordered_xn = (int *)malloc(nPoint * sizeof(int));

        if (xn != NULL) 
        {
            printf("Enter the input sequence separating each sample value with a white space.\n");
            
            for(i=0; i< nPoint; i++)
            {
                /* Input the sample at this location. */
                scanf("%d", &(xn[i]));
            }

            /* Print the sequence input. */
            printf("\nYou input the following sequence. \n");
            FFT_Print_Input(xn, nPoint);

            FFT_Reorder_Input(xn, reordered_xn);
        }
        else
        {
            /* Error occured in the program. Restart the program. */
            printf("\nError occured in the program. Restart the program\n");
            return -1;
        }

    }
    else
    {
        printf("Number is not a power of two\n");
    }

#endif
#if 0
    for(i=0; i< sample_point; i++)
    {
        Wn = FFT_Calculate_Twiddle_Value(i, sample_point);
        printf("W%d\t\t%f +j %f\n", i, Wn.real, Wn.imag);
    }
#endif
   
    return 0;
}

/* Wn = exp(j2*PI/N)*/
/* exp(j*theta) = cos(theta) + jsin(theta)*/
COMPLEX FFT_Calculate_Twiddle_Value(int power, int sample_pt)
{
    double mul_factor;
    int theta;
    COMPLEX     Wn;

    mul_factor = 2*PI / sample_pt;
    theta = mul_factor*power;

    /* Calcult*/
    Wn.real = cos(theta);
    Wn.imag = sin(theta);

    return Wn;

}

void FFT_Program_Info(void)
{
    printf("\n\t***********************************************************");
    printf("\n\t*                                                         *");
    printf("\n\t**********        Humble FFT demonstrator        **********");
    printf("\n\t*                                                         *");
    printf("\n\t* This program calculates the n-DFT of the sequence input,*");
    printf("\n\t* where n is input by the user. The program can be used   *");
    printf("\n\t* for any value of n that is a integral power of two.     *");
    printf("\n\t*                                                         *");
    printf("\n\t**********     Kaleem Anwar **********");
    printf("\n\t*                                                         *");
    printf("\n\t***********************************************************");
    printf("\n\n");
}


BOOLEAN FFT_Check_PowerOfTwo(int nPoint)
{
#if my
    int isPowerOfTwo, prod;

    Min_Bits_For_n =0;
    if (!(nPoint%2))
    {
        prod = 1;
        while (prod < nPoint) 
        {
            prod = prod * 2;

            Min_Bits_For_n++;
        }

        if (prod == nPoint) 
        {
            /* Yes the number is a power of two. */
            isPowerOfTwo = TRUE;
        }
        else
        {
            /* The number cannot be power of two as it is not 
               completely divisible by two. */
            isPowerOfTwo = FALSE;
        }

    }
    else
    {
        /* The number cannot be power of two as it is not 
           completely divisible by two. */
        isPowerOfTwo = FALSE;
    }
#else
    int i=0, power;
    BOOLEAN isPowerOfTwo;
    do 
    {
    	power = pow(2, i);
        i++;

    } while(power <= nPoint);

    if (prod == nPoint) 
    {
        /* Yes the number is a power of two. */
        isPowerOfTwo = TRUE;
    }
    else
    {
        /* The number cannot be power of two as it is not 
           completely divisible by two. */
        isPowerOfTwo = FALSE;
    }

#endif /* my */
    /* Return the status to indicate that the input number is a power of 
       two/not a power of two. */
    return isPowerOfTwo;

}

void FFT_Print_Input(int *samples, int sample_count)
{
    int i;
    for(i=0; i< sample_count; i++)
    {
        printf("%d ", samples[i]);
    }

    printf("\n");

}


void FFT_Reorder_Input(int *in_sequence, int *reordered_sequence, long sample_count)
{

    unsigned long index[64];
    int i=0;

    index[i] = 0;
    for(i=1; i< sample_count; i++)
    {


    }

    

}

void FFT_Reverse_Bit_Sequence(int n, int *rev_n)
{
    int int_size = sizeof(int);
    int i, temp1=0, temp2;

    int_size *= 8;
    temp2 = n;
    for(i=1; i<Min_Bits_For_n; i++)
    {
        temp1+= temp2 & 1;
        temp1 = temp1 << 1;
        temp2 = n >> i;
    }

    printf("bits: %d\n", Min_Bits_For_n);
    printf("in: %d\n", n);
    printf("rev: %d\n", temp1);
    *rev_n = temp1;
}



























