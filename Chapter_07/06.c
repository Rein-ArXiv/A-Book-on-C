/* Chapter 7 exercise 6 */

/* 32 비트 수식의 비트들로부터 1 비트씩 건너뛰면서 비트를 추출하는 함수를 작성
 * 하여라. 결과는 16 비트 수식으로 리턴되어야 한다. 또한 작성한 함수는 2 바이트
 * 나 4 바이트 워드 컴퓨터에서 모두 수행될 수 있어야 한다.
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

uint16_t extract_alternating_bits(uint32_t input) {
    uint16_t result = 0;
    int i;

    for (i = 0; i < 16; i++) {
        // 홀수 번째 비트 추출 (0, 2, 4, ...)
        if (input & (1u << (2 * i))) {
            result |= (1u << i); // 추출된 비트를 result의 해당 위치에 설정
        }
    }

    return result;
}

// 비트 출력 함수 (보조 함수)
void print_bits(uint32_t num, int num_bits) {
    unsigned long mask = 1UL << (num_bits - 1); // 최상위 비트 마스크 생성
    for (int i = 0; i < num_bits; i++) {
        putchar((num & mask) ? '1' : '0'); // 비트 값 출력
        mask >>= 1; // 마스크 오른쪽 시프트
        if (i % 8 == 7 && i < num_bits - 1) { // 8비트마다 공백 삽입
            putchar(' ');
        }
    }
    putchar('\n');
}

int main() {
    uint32_t a;
    uint16_t result;

    printf("Input num: ");
    scanf("%" SCNu32, &a);

    result = extract_alternating_bits(a);

    printf("Original 32bit Decimal  : %" PRIu32 "\n", a);
    printf("Original 32bit Binary   : ");
    print_bits(a, sizeof(uint32_t) * CHAR_BIT);

    printf("Extracted 16bit Decimal : %" PRIu16 "\n", result);
    printf("Extracted 16bit Binary  : ");
    print_bits(result, sizeof(uint16_t) * CHAR_BIT);

    return 0;
}