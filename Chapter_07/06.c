/* Chapter 7 exercise 6 */

/* 32 비트 수식의 비트들로부터 1 비트씩 건너뛰면서 비트를 추출하는 함수를 작성
 * 하여라. 결과는 16 비트 수식으로 리턴되어야 한다. 또한 작성한 함수는 2 바이트
 * 나 4 바이트 워드 컴퓨터에서 모두 수행될 수 있어야 한다.
 */

#include <stdio.h>
#include <limits.h>

#define LONG_BIT 32

short interleave_bit(long a)
{
    int i;
    int n = LONG_BIT;
    long mask = 1 << (LONG_BIT - 1);
    short result = 0;

    
    for (int i=LONG_BIT-1; i >= 0; i-=2){
        result += mask & a;
        mask >>= 2;
        result >>= 1;
    }
    return result;
}

void bit_print(long a)
{
    int i;
    int n = LONG_BIT;
    long mask = 1 << (n - 1);

    
    for (i = 1; i <= n; i++){
        putchar(((a & mask) == 0) ? '0' : '1');

        a <<= 1;

        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }
    putchar('\n');
}

void short_bit_print(short a)
{
    short i;
    short n = sizeof(short) * CHAR_BIT;
    short mask = 1 << (n - 1);

    
    for (i = 1; i <= n; i++){
        putchar(((a & mask) == 0) ? '0' : '1');

        a <<= 1;

        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }
    putchar('\n');
}


int main(void){
   long a;
   short result;

   printf("Input integer: ");
   scanf("%d", &a);

   result = interleave_bit(a);

   printf("Original long:   %ld\n", a);
   printf("Original bit:    ");
   bit_print(a);

   printf("Extracted short: %d\n", result);
   printf("Extracted bit:   ");
   short_bit_print(result);
   return 0;
}