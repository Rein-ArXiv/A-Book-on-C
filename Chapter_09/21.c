/* Chapter 9 exercise 21 */

/* 상업적 응용 프로그램에서는 4개의 이진 숫자로 10진 숫자를 나타내는 2진화 10
 * 진 코드(BCD)가 유용한 경우가 있다. 32비트 워드는 8개의 10진 숫자를 나타내는
 * 데 사용될 수 있다. 비트 필드를 사용하여 구현해 보아라. 그리고 2진수에서 BCD
 * 로, BCD에서 2진수로 변환하는 프로그램을 작성하여라.
 */

#include <stdio.h>
#include <stdint.h>


typedef struct {
    unsigned int digit0 : 4;
    unsigned int digit1 : 4;
    unsigned int digit2 : 4;
    unsigned int digit3 : 4;
    unsigned int digit4 : 4;
    unsigned int digit5 : 4;
    unsigned int digit6 : 4;
    unsigned int digit7 : 4;
} BCDWord;

void print_bcd_word(BCDWord bcd) {
    printf("%X%X%X%X%X%X%X%X\n", 
           bcd.digit7, bcd.digit6, bcd.digit5, bcd.digit4, 
           bcd.digit3, bcd.digit2, bcd.digit1, bcd.digit0);
}

BCDWord decimal_to_bcd_word(int decimal) {
    BCDWord bcd;
    bcd.digit0 = decimal % 10; decimal /= 10;
    bcd.digit1 = decimal % 10; decimal /= 10;
    bcd.digit2 = decimal % 10; decimal /= 10;
    bcd.digit3 = decimal % 10; decimal /= 10;
    bcd.digit4 = decimal % 10; decimal /= 10;
    bcd.digit5 = decimal % 10; decimal /= 10;
    bcd.digit6 = decimal % 10; decimal /= 10;
    bcd.digit7 = decimal % 10;
    return bcd;
}

int bcd_word_to_decimal(BCDWord bcd) {
    return bcd.digit7 * 10000000 + bcd.digit6 * 1000000 + 
           bcd.digit5 * 100000 + bcd.digit4 * 10000 + 
           bcd.digit3 * 1000 + bcd.digit2 * 100 + 
           bcd.digit1 * 10 + bcd.digit0;
}

uint32_t decimal_to_bcd(int decimal)
{
    uint32_t bcd = 0;
    int shift = 0;

    while (decimal > 0 && shift < 32){
        int digit = decimal % 10;
        bcd = bcd | (digit << shift);
        decimal /= 10;
        shift += 4;
    }

    return bcd;
}

int bcd_to_decimal(uint32_t bcd)
{
    int decimal = 0;
    int multiplier = 1;

    while (bcd > 0)
    {
        int digit = bcd & 0xF;
        decimal = decimal + digit * multiplier;
        bcd >>= 4;
        multiplier *= 10;
    }
    return decimal;
}

int main(void){
    int decimal = 12345678;

    BCDWord word = decimal_to_bcd_word(decimal);
    printf("BCD representation: ");
    print_bcd_word(word);

    int recovered_decimal = bcd_word_to_decimal(word);
    printf("Recovered cdecimal: %d\n", recovered_decimal);

    uint32_t bcd32 = decimal_to_bcd(decimal);
    printf("BCD (32-bit) representation: %08X\n", bcd32);     // HEX

    int recovered_decimal32 = bcd_to_decimal(bcd32);
    printf("Recovered decimal from 32-bit BCD: %d\n", recovered_decimal32);

    return 0;
}