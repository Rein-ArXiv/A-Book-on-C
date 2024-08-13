/* Chapter 9 exercise 29 */

/* 다음 프로그램은 시스템 종속적이지만 모든 시스템에서 정상적으로 실행될 것이
 * 다. 각자의 시스템에서 올바르게 수행되는지 실행시켜 보아라.

    #include <stdio.h>

    #if (VAX || PC)
        #define     HEX0    0x6c6c6548
        #define     HEX1    0x77202c6f
        #define     HEX2    0x646c726f
        #define     HEX3    0x00000a21
    #else
        #define     HEX0    0x48656c6c
        #define     HEX1    0x6f2c2077
        #define     HEX2    0x6f726c64
        #define     HEX3    0x210a0000
    #endif

    typedef union {
        char what[16];
        long cipher[4];
    } mystery;

    int main(void)
    {
        mystery x;      // put a hex on the mystery

        x.cipher[0] = HEX0;
        x.cipher[1] = HEX1;
        x.cipher[2] = HEX2;
        x.cipher[3] = HEX3;

        printf("%s\n", x.what);

        return 0;
    }

 * 이 mystery 프로그램이 어떻게 동작하는지를 설명하여라. 출력된 문장에 익숙하
 * 지 않다면, 경험이 많은 C 프로그래머에게 물어보아라.
 */

/* The mystery program. */

#include <stdio.h>

#if (VAX || PC)
    #define     HEX0    0x6c6c6548
    #define     HEX1    0x77202c6f
    #define     HEX2    0x646c726f
    #define     HEX3    0x00000a21

// If you use Big Endian:
/*
#else
    #define     HEX0    0x48656c6c
    #define     HEX1    0x6f2c2077
    #define     HEX2    0x6f726c64
    #define     HEX3    0x210a0000
#endif
*/

// If you use Little Endian:
#else
    #define     HEX0    0x6c6c6548
    #define     HEX1    0x77202c6f
    #define     HEX2    0x646c726f
    #define     HEX3    0x00000a21
#endif


typedef union {
    char what[16];
    long cipher[4];
} mystery;

int main(void)
{
    mystery x;      // put a hex on the mystery

    x.cipher[0] = HEX0;
    x.cipher[1] = HEX1;
    x.cipher[2] = HEX2;
    x.cipher[3] = HEX3;

    printf("%s", x.what);

    return 0;
}