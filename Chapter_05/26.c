/* Chapter 5 exercise 26 */

/* 확률적 사건에 대하여 난수 발생기를 연속적으로 사용하는 모의 실험을 몬테 카
 * 를로(Monte Carlo) 시뮬레이션이라고 한다. 이렇게 부르는 이유는 몬테 카를로가
 * 세계에서 가장 유명한 카지노 게임이 벌어지는 곳 중 하나이기 때문이다. 이 기술
 * 을 변형된 생일 문제에서 분기점을 찾는데 사용해 보자. (6장 연습 문제 36번을
 * 참조하여라.) 사람이 가득한 방에서, 그들 중 적어도 두 명은 같은 해 같은 날이
 * 생일일 수 있다. 일반적인 파티 게임은 이것이 사실인지를 조사하는 것이다. 먼저
 * n명의 사람이 있는 방에서 임의의 두 사람이 같은 달에 태어났을 확률을 찾기를
 * 원한다. (같은 날에 대해 이와 같은 분석을 하려면 배열을 사용해야 하지만, 개념
 * 은 같다.) 방에 한 사람만 있다면, 확률은 분명히 0이다. 두 사람일 경우는 확률이
 * 1/12이다. (각 사람이 특정한 달에 태어날 확률은 동일하다고 가정하자. 실제 상황
 * 에서는 근사치일 뿐이다.) 방에 2, 3, ..., 20명이 있을 경우에 대해, 각각 1,000번
 * 수행하여 확률을 모의 실험해 보아라. 각 달에 태어난 사람의 수를 계산하기 위해
 * 12개 변수를 사용하여라. 각 사람이 태어난 달을 생성하기 위해 다음 수식을 사용
 * 할 수 있다.
 
    rand() % 12 + 1
 
 * (lrand48() 같은 더 좋은 난수 발생기를 사용할 수 있으며, 그것을 사용하여라.)
 * 이 수식은 1부터 12까지 임의로 분포된 정수를 생성한다. 12개의 변수 중 어떤 변
 * 수의 값이 2라면, 이 시도는 참이고, 이것은 적어도 방에 있는 두 사람이 같은 달
 * 에 태어났음을 의미한다. 참인 시도의 합을 1,000으로 나누면, 모의 실험한 확률이
 * 된다. 확률이 1/2 또는 그 이상이 되는 가장 작은 n 값을 찾아라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMULATIONS 1000
#define MAX_PEOPLE 20

int main() {
    int n, i, j, success, found;
    int month_count[12]; // Array to count the number of people born in each month

    srand(time(NULL)); // Seed the random number generator

    // Loop from 2 to MAX_PEOPLE to find the smallest n with probability >= 0.5
    for (n = 1; n <= MAX_PEOPLE; n++) {
        success = 0;

        // Perform SIMULATIONS trials
        for (i = 0; i < SIMULATIONS; i++) {
            // Reset month counts
            for (j = 0; j < 12; j++) {
                month_count[j] = 0;
            }

            // Assign random birth months for n people
            for (j = 0; j < n; j++) {
                int month = rand() % 12; // Generate a month (0 to 11)
                month_count[month]++;
            }

            // Check if any month count is 2 or more
            found = 0;
            for (j = 0; j < 12; j++) {
                if (month_count[j] > 1) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                success++;
            }
        }

        // Calculate probability
        double probability = (double)success / SIMULATIONS;
        printf("n = %d: Probability = %.3f\n", n, probability);

        // Check if probability is 50% or more
        if (probability >= 0.5) {
            printf("The smallest n with a probability of at least 0.5 is %d\n", n);
            break;
        }
    }

    return 0;
}
