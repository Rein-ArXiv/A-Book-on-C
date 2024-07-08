/* Chapter 9 exercise 23 */

/* (에라토스테네스의 체) 에라토스테네스의 체는 소수를 찾아내는 알고리즘으로, 기
 * 본 개념은 주어진 숫자 중에서 소수의 모든 배수를 지워서 최종적으로 남는 수를
 * 소수로 하는 것이다. 이 알고리즘을 사용하여 32000보다 작은 소수를 찾아내는 프
 * 로그램을 다음에 기술하는 대로 작성하여라. 먼저 이 알고리즘의 구현을 위해 비
 * 트 필드로 나누어진 한 워드를 멤버로 하는 구조체의 배열을 사용하여라. 여기서
 * 각각의 비트 필드는 하나의 정수를 의미하고, 따라서 하나의 구조체는 32개의 수
 * 를 표현할 수 있다. 32000보다 작은 소수를 찾아내기 위해서는 1000개의 구조체로
 * 이루어진 배열이 필요하며, 각 비트 필드의 초기 값은 0으로 하고 소수가 아닌 것
 * 이 판단되면 1로 만든다. 프로그램의 동작은 다음과 같다. 먼저 소수 2에서부터
 * 시작한다. 4부터 시작하여 모든 2의 배수에 해당되는 비트 필드를 1로 한다. 그
 * 다음 3을 위한 비트 필드를 보면 0이므로, 소수임을 알 수 있다. 그리고 6부터 모
 * 든 3의 배수에 해당되는 비트 필드를 1로 만든다. 그 다음 4를 위한 비트 필드는
 * 1이므로 소수가 아님을 알 수 있다. 그리고 그 다음 수 5를 위한 비트 필드를 보
 * 면 0이므로, 이는 소수임을 알 수 있고 10부터 시작하여 5의 배수에 해당하는 모
 * 든 비트 필드를 1로 만든다. 이런 식으로 32000까지 반복하여, 이때까지 비트 필
 * 드 값이 0인 수는 소수임을 알 수 있다.
 */

#include <stdio.h>

#define MAX_NUM 32000
#define NUM_WORDS (MAX_NUM / 32 + 1)

typedef struct {
    unsigned int bits : 32;
} BitField;

BitField sieve[NUM_WORDS];

void set_bit(int n) {
    sieve[n / 32].bits |= (1U << (n % 32));
}

int get_bit(int n) {
    return (sieve[n / 32].bits & (1U << (n % 32))) != 0;
}

void clear_bit(int n) {
    sieve[n / 32].bits &= ~(1U << (n % 32));
}

void initialize_sieve() {
    for (int i = 0; i < NUM_WORDS; i++) {
        sieve[i].bits = 0;
    }
}

void eratosthenes_sieve() {
    initialize_sieve();

    for (int i = 2; i * i < MAX_NUM; i++) {
        if (!get_bit(i)) {
            for (int j = i * i; j < MAX_NUM; j += i) {
                set_bit(j);
            }
        }
    }
}

void print_primes() {
    for (int i = 2; i < MAX_NUM; i++) {
        if (!get_bit(i)) {
            printf("%d\n", i);
        }
    }
    printf("\n");
}

int main() {
    eratosthenes_sieve();
    print_primes();
    return 0;
}