/* Chapter 5 exercise 24 */

/* 표준 라이브러리에 있는 난수 발생기 rand()를 사용하여 동전 던지기를 모의 실
 * 험하는 프로그램을 작성하여라. 수식 rand() % 2를 사용하여 int 값 0이나 1을
 * 생성하여라. 앞면은 1로, 뒷면은 0으로 나타낸다고 하자. 이 프로그램을 1,000번,
 * 10,000번, 100,0000번 수행하고, 앞면이 계속 나오는 경우의 가장 긴 수열과
 * 101010...과 같이 앞면과 뒷면이 번갈아 계속해서 나오는 경우의 가장 긴 수열을
 * 조사하여라. 확률 이론을 알고 있다면, 이 모의 실험이 이론에 근거함을 알 수 있
 * 다. 주의: 어떤 전통적인 C 시스템에서, 함수 rand()의 성능은 아주 나쁘다. 즉,
 * 앞면과 뒷면이 번갈아 계속 나오는 하나의 긴 순열을 얻을 것이다. 여러분이 사용
 * 하는 ANSI C 시스템이 특정한 수식을 사용한다면, 이 연습문제는 아주 흥미 있
 * 는 문제는 아닐지도 모른다.
 */

#include <stdio.h>
#include <stdlib.h>

int coin(void);

int main(void)
{
    int before_coin, current_coin;
    int head_sequence_max = 1, head_sequence_length = 1;
    int flip_sequence_max = 1, flip_sequence_length = 1;
    int coin_toss_num, i;

    printf("Input coin toss num: ");
    scanf("%d", &coin_toss_num);

    before_coin = coin();
    current_coin = before_coin;

    for (i = 1; i < coin_toss_num; i++) {
        current_coin = coin();

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

int coin(void)
{
    return rand() % 2;  // Head : 1, Tail : 0
}
