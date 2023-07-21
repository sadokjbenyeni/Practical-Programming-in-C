#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>


int main(void)
{
    printf("On a 64-bit machine:\n");
    printf("    Type     | Size |    MIN    |    MAX    \n");
    printf("char          %4ld %9d %11d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("unsigned char %4ld %9d %11d\n", sizeof(unsigned char), 0, UCHAR_MAX);
    printf("short         %4ld %9d %11d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("int           %4ld %13d %11d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned int  %4ld %7u %17u\n", sizeof(unsigned int), -UINT_MAX - 1, UINT_MAX);
    printf("unsigned long %4ld %7lu %27lu\n", sizeof(unsigned long), -ULONG_MAX - 1, ULONG_MAX);
    printf("float         %4ld %11f %10f\n", sizeof(float), FLT_MIN, FLT_MAX);
    
    return 0;
}