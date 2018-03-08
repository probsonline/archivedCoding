
/* Structure for handling Complex Numbers. */
typedef struct COMPLEX_STRUCT
{
	double real;
	double imag;	

} COMPLEX;

/* Array of Complex Number containing the FFT constants. */
COMPLEX fft_constants[];

/* Function prototypes. */
void    Calculate_Butterfly();
COMPLEX Calculate_Twiddle_Value();

/* Main function to test the algorithm. */
void main()
{
}
