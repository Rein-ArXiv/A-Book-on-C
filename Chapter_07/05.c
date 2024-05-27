/* Chapter 7 exercise 5 */

/* int의 비트 표현을 다음과 같이 역전시키는 함수를 작성하여라. 다음은 char에
 * 대한 예제이다.
 
    01110101을 역전시키면 10101110이 된다.
    10101111을 역전시키면 11110101이 된다.

 */

#include <stdio.h>
#include <limits.h>

#define INT_BIT 32

int reverse_bit(int a){
   int rev = -1;
   int result = a ^ rev;
   return result;
}

void bit_print(int a)
{
    int i;
    int n = INT_BIT;
    int mask = 1 << (n - 1);

    
    for (i = 1; i <= n; i++){
        putchar(((a & mask) == 0) ? '0' : '1');

        a <<= 1;

        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }
    putchar('\n');
}

int main(void){
   int a;
   int result;

   printf("Input integer: ");
   scanf("%d", &a);

   result = reverse_bit(a);

   printf("Original int: %d\n", a);
   printf("Original bit: ");
   bit_print(a);

   printf("Reversed int: %d\n", result);
   printf("Reversed bit: ");
   bit_print(result);
   return 0;
}