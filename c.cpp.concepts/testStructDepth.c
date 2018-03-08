#include <stdio.h>

#define	LOOP 2

typedef struct aa_struct
{
    int     num;

} simpleStrut;

typedef struct k_struct
{
    int      deep_num;
} K;

typedef struct j_struct
{
    K       ks;
} J;

typedef struct i_struct
{
    J       js;
} I;

typedef struct h_struct
{
    I       is;
} H;

typedef struct g_struct
{
    H       hs;
} G;

typedef struct f_struct
{
    G       gs;
} F;

typedef struct e_struct
{
    F       fs;
} E;

typedef struct d_struct
{
    E       es;
} D;

typedef struct c_struct
{
    D       ds;
} C;

typedef struct b_struct
{
    C       cs;
} B;


typedef struct a_struct
{
    B       bs;
} A;

typedef A deepStruct;

int main( int argc, char *argv[] )
{
    int i;
    simpleStrut ss;
    deepStruct  ds;

    printf( "Simple!\n" );

    for(i=0; i<LOOP; i++)
    {
        ss.num = i;
        printf("%u\t", ss.num);
    }

    printf( "\nDeep!\n" );

    for(i=0; i<LOOP; i++)
    {
        ds.bs.cs.ds.es.fs.gs.hs.is.js.ks.deep_num=i;
        printf("%u\t", ds.bs.cs.ds.es.fs.gs.hs.is.js.ks.deep_num);
    }

    return 0;
}
