/* Chapter 5 exercise 24 */

/* rand() 함수가 아닌 다른 난수 발생기를 사용할 수 있다면, 앞의 연습 문제에서
 * 작성한 프로그램이 그 함수를 사용할 경우 어떻게 되는지 실험해 보아라. 실험 결
 * 과가 다른가?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MT_N 624
#define MT_M 397
#define MT_MATRIX_A 0x9908b0df
#define MT_UPPER_MASK 0x80000000
#define MT_LOWER_MASK 0x7fffffff

static unsigned int mt[MT_N];
static int mti = MT_N + 1;

void mt_init(unsigned int seed);
unsigned int mt_generate(void);

int main(void)
{
    int before_coin, current_coin;
    int head_sequence_max = 1, head_sequence_length = 1;
    int flip_sequence_max = 1, flip_sequence_length = 1;
    int coin_toss_num, i;

    mt_init(5489U);
    printf("Input coin toss num: ");
    scanf("%d", &coin_toss_num);

    before_coin = mt_generate();
    current_coin = before_coin;

    for (i = 1; i < coin_toss_num; i++) {
        current_coin = mt_generate();

        if (before_coin != current_coin){
            flip_sequence_length++;
        }
        else{
            flip_sequence_length = 1;
        }

        if (before_coin == 1 && current_coin == 1){
            head_sequence_length++;
        }

        else if (current_coin == 1){
            head_sequence_length = 1;
        }

        else{
            head_sequence_length = 0;
        }

        if (head_sequence_length > head_sequence_max){
            head_sequence_max = head_sequence_length;
        }

        if (flip_sequence_length > flip_sequence_max){
            flip_sequence_max = flip_sequence_length;
        }

        before_coin = current_coin;
    }

    printf("Max head sequence length: %d\n", head_sequence_max);
    printf("Max flip sequence length: %d\n", flip_sequence_max);

    return 0;
}

void mt_init(unsigned int seed) {
    mt[0] = seed;
    for (mti = 1; mti < MT_N; mti++) {
        mt[mti] = (1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti);
    }
}

unsigned int mt_generate(void) {
    unsigned int y;
    static unsigned int mag01[2] = {0x0, MT_MATRIX_A};

    if (mti >= MT_N) {
        int kk;

        if (mti == MT_N + 1) {
            mt_init(5489U);
        }

        for (kk = 0; kk < MT_N - MT_M; kk++) {
            y = (mt[kk] & MT_UPPER_MASK) | (mt[kk + 1] & MT_LOWER_MASK);
            mt[kk] = mt[kk + MT_M] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        for (; kk < MT_N - 1; kk++) {
            y = (mt[kk] & MT_UPPER_MASK) | (mt[kk + 1] & MT_LOWER_MASK);
            mt[kk] = mt[kk + (MT_M - MT_N)] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        y = (mt[MT_N - 1] & MT_UPPER_MASK) | (mt[0] & MT_LOWER_MASK);
        mt[MT_N - 1] = mt[MT_M - 1] ^ (y >> 1) ^ mag01[y & 0x1];
        mti = 0;
    }

    y = mt[mti++];

    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680;
    y ^= (y << 15) & 0xefc60000;
    y ^= (y >> 18);

    return y % 2;
}