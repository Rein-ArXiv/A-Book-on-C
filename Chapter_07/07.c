/* Chapter 7 exercise 7 */

/* 10진 정수의 열을 입력으로 하는 함수를 작성하여라. 그 열의 각 문자는 하나의
 * 10진 문자로 볼 수 있다. 각 숫자는 4 비트의 이진수 열로 변환되어야하고, 그것
 * 은 int 형에 패킹되어야 한다. 만일 int 형이 32 비트이면, 8개의 숫자가 패킹될 
 * 수 있다. 이 함수의 수행결과를 다음과 같이 나오도록 하여라.
 
    Input a string of decimal digits : 12345678
    12345678 = 0001 0010 0011 0100 0101 0110 0111 1000
 
 * 또한, 역함수도 작성하여라. 역함수는 int를 언패킹하여 원래의 열을 리턴해야 한
 * 다. 힌트: 변환 함수는 다음과 같이 시작할 수도 있을 것이다.
 
    int convert(char *s)
    {
        char *p;
        int a = 0;      // turn all bits off

        for (p = s; *p != '\0'; ++p){
            a << = 4;
            switch (*p) {
                case '1':
                    a |= 1;
                    break;
                case '2';
                .....

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define INT_PACKING_MAXLEN (sizeof(int) * CHAR_BIT / 4)

int convert(char *s);
void bit_print(int a);
char* rewind_convert(int a, char *buffer);

int main(void)
{
    char s[100];
    int converted_num;
    char rewind_converted_num[100];
    printf("Input a string of decimal digits: ");
    fgets(s, sizeof(s), stdin);

    s[strcspn(s, "\n")] = '\0';

    if (strlen(s) <= INT_PACKING_MAXLEN){
        converted_num = convert(s);
        printf("%s = ", s);
        bit_print(converted_num);
        rewind_convert(converted_num, rewind_converted_num);
        printf("Rewind converting: %s\n", rewind_converted_num);
    }
    else{
        printf("ERROR: Input number's length should be under 8 digits.");
        exit(1);
    }

    return 0;
}

int convert(char *s)
{
    char *p;
    int a = 0;      // turn all bits off

    for (p = s; *p != '\0'; ++p){
        a = (a << 4) | (*p - '0');
    }
    return a;
}

void bit_print(int a)
{
    int i;
    int n = sizeof(int) * CHAR_BIT;
    int mask = 1 << (n - 1);
    
    for (i = 1; i <= n; i++){
        putchar(((a & mask) == 0) ? '0' : '1');

        a <<= 1;

        if (i % 4 == 0 && i < n)
            putchar(' ');
    }
    putchar('\n');
}

char* rewind_convert(int a, char *buffer)
{
    for(int i = 0; i < INT_PACKING_MAXLEN; i++){
        int val = (a >> (4 * i)) & (0b1111);
        buffer[INT_PACKING_MAXLEN - 1 - i] = val + '0';
    }
    buffer[INT_PACKING_MAXLEN] = '\0';
    return buffer;
}
