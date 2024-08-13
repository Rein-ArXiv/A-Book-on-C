/* Chapter 7 exercise 2 */

/* Alice, Betty, Carole이 16가지의 투표를 한다고 가정하자. 그리고 각 개인의 16개
 * 의 투표는 16 비트 정수에 비트별로 저장된다고 가정하자. 다음과 같이 시작되는
 * 함수를 작성하여라.
 
    short majority(short a, short b, short c)
    {
        .....
    }

 * 이 함수는 a, b, c에 각각 저장된 Alice, Betty, Carole의 투표를 입력으로 한다.
 * 그리고, 이 함수는 그 투표 결과를 16 비트에 저장하여 리턴해야 한다. 즉, a, b,
 * c를 비트단위로 비교하여, 1의 값이 더 많으면 그 결과 비트를 1로 하고, 0이 더 
 * 많으면 결과 비트를 0으로 한다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

short majority(short a, short b, short c)
{
    short result = 0;
    short n = sizeof(short) * CHAR_BIT;
    short mask = 1;
    int count = 0;
    
    for (int i = 1; i <= n; i++){
        count = 0;
        if (a & mask)
            count++;
        
        if (b & mask)
            count++;
        
        if (c & mask)
            count++;
        
        if (count >= 2){
            result += 1 * mask;
        }
        mask <<= 1;
    }
    return result;
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

int main(void)
{
    srand(time(NULL));
    short a, b, c, result;
    
    a = rand() % SHRT_MAX;
    b = rand() % SHRT_MAX;
    c = rand() % SHRT_MAX;
    
    printf("Alice:  ");
    short_bit_print(a);
    printf("Betty:  ");
    short_bit_print(b);
    printf("Carole: ");
    short_bit_print(c);
    
    result = majority(a, b, c);
    
    printf("Result: ");
    short_bit_print(result);

    return 0;
}

