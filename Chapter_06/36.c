/* Chapter 6 exerecise 36 */

/* 확률적 사건에 대하여 난수 발생기를 연속적으로 사용한느 모의 실험을 몬테 카 
 * 를로 시뮬레이션이라고 한다. 이렇게 부르는 이유는 몬테 카를로가 세계에서 가장
 * 유명한 카지노 게임이 벌어지는 곳 중 하나이기 때문이다. 이 연습 문제에서는 n
 * 명의 사람이 있는 방에서 최소한 두 사람의 생일이 같은 해 같은 날짜일 확률을
 * 구하려고 한다. 1년이 365일이라 가정하고, 그 해에 각 날에 태어날 확률은 같다
 * 고 가정하자. 한 번의 시도는 크기가 n인 배열을 1과 365 사이에서 임의적으로 분
 * 포된 정수로 채우는 것으로 구성된다. 만일 그 배열의 어떤 2개의 원소가 똑같은
 * 값을 가지고 있다면, 이 시도는 "참"이라고 한다. 따라서 참 시도는 그해 같은 날
 * 에 태어난 사람이 최소한 두 사람이 있는 경우와 같다. n명의 사람에 대하여
 * 10,000번을 시도하여 확률을 모의 실험해보아라. 이 작업을 n = 2, 3, ..., 100에 대
 * 하여 해 보아라. 각 사람의 생일을 구할 때, 다음 수식을 사용하면 된다.

    rand() % 365 + 1

 * (가능하다면, 더 나은 난수를 생성하는 lrand48()을 사용하여라.) 참 시도의 수
 * 를 10,000으로 나눈 것이 모의 실험의 확률이다. 확률이 1/2 이상이 되는 최소의
 * n 값을 찾아라.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergesort/mergesort.h"

#define TRIAL 10000
#define PEOPLE 100

int main(void)
{
    srand(time(NULL));
    int i, j, n, same_birthday = 0, same_birthday_count = 0;
    double probability;

    for (n = 2; n <= PEOPLE; n++){
        int birthday[n];
        same_birthday_count = 0;
        for (i = 0; i < TRIAL; i++){
            for (j = 0; j < n; j++){
                birthday[j] = rand() % 365 + 1;    
            }
            mergesort(birthday, 0, n - 1);
            
            same_birthday = 0;
            for (j = 0; j < n - 1; j++){
                if (birthday[j] == birthday[j + 1]){
                    same_birthday = 1;
                    break;
                }
            }
            same_birthday_count += same_birthday;
        }
        probability = (double) same_birthday_count / TRIAL;

        printf("People number: %d, Same birthday probability: %lf\n", n, probability);
    }
    return 0;
}